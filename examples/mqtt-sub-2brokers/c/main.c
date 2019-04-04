#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "MQTTClient.h"

#define ADDRESS_1     "tcp://localhost:1883"
#define TOPIC_1       "NombreEquipoSub1"
#define ADDRESS_2     "tcp://localhost:1884"
#define TOPIC_2       "NombreEquipoSub2"
#define TIMEOUT       10000L

volatile MQTTClient_deliveryToken deliveredtoken;

int msgarrvd(void *context, char *topicName, int topicLen, MQTTClient_message *message)
{
    int i;
    char* payloadptr;

    printf("Message arrived\n");
    printf("     topic: %s\n", topicName);
    printf("   message: ");

    payloadptr = message->payload;
    for(i=0; i<message->payloadlen; i++)
    {
        putchar(*payloadptr++);
    }
    putchar('\n');
    MQTTClient_freeMessage(&message);
    MQTTClient_free(topicName);
    return 1;
}

void connlost(void *context, char *cause)
{
    printf("\nConnection lost\n");
    printf("     cause: %s\n", cause);
}

int main(int argc, char* argv[])
{
    MQTTClient client, client2;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    int rc;
    int ch;

    // Generate random client id
    char cli_id[40];
    sprintf(cli_id, "%s-%u", "IkerlanHackathon", (unsigned int)time(NULL));

    // Create MQTT Client 1
    MQTTClient_create(&client, ADDRESS_1, cli_id,
        MQTTCLIENT_PERSISTENCE_NONE, NULL);
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;

    MQTTClient_setCallbacks(client, NULL, connlost, msgarrvd, NULL);

    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to connect, return code %d\n", rc);
        exit(EXIT_FAILURE);
    }
    printf("Subscribing with client %s to topic %s\n\n", cli_id, TOPIC_1);
    MQTTClient_subscribe(client, TOPIC_1, 0);

    // Create MQTT Client 2
    MQTTClient_create(&client2, ADDRESS_2, cli_id,
        MQTTCLIENT_PERSISTENCE_NONE, NULL);
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;

    MQTTClient_setCallbacks(client2, NULL, connlost, msgarrvd, NULL);

    if ((rc = MQTTClient_connect(client2, &conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to connect, return code %d\n", rc);
        exit(EXIT_FAILURE);
    }
    printf("Subscribing with client %s to topic %s\n\n", cli_id, TOPIC_2);
    MQTTClient_subscribe(client2, TOPIC_2, 0);

    printf("Press Q<Enter> to quit\n\n");

    do 
    {
        ch = getchar();
    } while(ch!='Q' && ch != 'q');

    MQTTClient_unsubscribe(client, TOPIC_1);
    MQTTClient_disconnect(client, 10000);
    MQTTClient_destroy(&client);

    MQTTClient_unsubscribe(client2, TOPIC_2);
    MQTTClient_disconnect(client2, 10000);
    MQTTClient_destroy(&client2);
    return rc;
}
