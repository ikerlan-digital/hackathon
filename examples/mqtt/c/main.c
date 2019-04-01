#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MQTTAsync.h"

#define ADDRESS         "tcp://127.0.0.1:1883"
#define CLIENTID        "NombreEquipo"
#define SUBSCRIBE_TOPIC "NombreEquipo/sub"
#define PUBLISH_TOPIC   "NombreEquipo/pub"
#define PAYLOAD         "Feel the green!"
#define QOS             0 
#define TIMEOUT         10000L

volatile MQTTAsync_token deliveredtoken;

int disc_finished = 0;
int subscribed = 0;
int finished = 0;

/* Connection lost callback */
void connlost(void *context, char *cause)
{
	MQTTAsync client = (MQTTAsync)context;
	MQTTAsync_connectOptions conn_opts = MQTTAsync_connectOptions_initializer;
	int rc;

	printf("\nConnection lost\n");
	if (cause)
		printf("     cause: %s\n", cause);

	printf("Reconnecting\n");
	conn_opts.keepAliveInterval = 20;
	conn_opts.cleansession = 1;
	if ((rc = MQTTAsync_connect(client, &conn_opts)) != MQTTASYNC_SUCCESS)
	{
		printf("Failed to start connect, return code %d\n", rc);
		finished = 1;
	}
}

/* Message arrived callback */
int msgarrvd(void *context, char *topicName, int topicLen, MQTTAsync_message *message)
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
    MQTTAsync_freeMessage(&message);
    MQTTAsync_free(topicName);
    return 1;
}

/* On Disconnect callback */
void onDisconnect(void* context, MQTTAsync_successData* response)
{
	printf("Successful disconnection\n");
	disc_finished = 1;
}

/* On subscribe callback */
void onSubscribe(void* context, MQTTAsync_successData* response)
{
	printf("Subscribe succeeded\n");
	subscribed = 1;
}

/* On subscribe failure callback */
void onSubscribeFailure(void* context, MQTTAsync_failureData* response)
{
	printf("Subscribe failed, rc %d\n", response ? response->code : 0);
	finished = 1;
}

/* On connect failure callback */
void onConnectFailure(void* context, MQTTAsync_failureData* response)
{
	printf("Connect failed, rc %d\n", response ? response->code : 0);
	finished = 1;
}

/* On connect callback */
void onConnect(void* context, MQTTAsync_successData* response)
{
	MQTTAsync client = (MQTTAsync)context;
	MQTTAsync_responseOptions opts = MQTTAsync_responseOptions_initializer;
	int rc;

	printf("Successful connection\n");

	printf("Subscribing to topic %s\nfor client %s using QoS%d\n\n"
           "Press Q<Enter> to quit\n\n", SUBSCRIBE_TOPIC, CLIENTID, QOS);
	opts.onSuccess = onSubscribe;
	opts.onFailure = onSubscribeFailure;
	opts.context = client;

	deliveredtoken = 0;

    /* As soon as it's connected, subscribe to SUBSCRIBE_TOPIC to receive
     * messages */
	if ((rc = MQTTAsync_subscribe(client, SUBSCRIBE_TOPIC, QOS, &opts)) != MQTTASYNC_SUCCESS)
	{
		printf("Failed to start subscribe, return code %d\n", rc);
		exit(EXIT_FAILURE);
	}
}


int main(int argc, char* argv[])
{
	MQTTAsync client;
	MQTTAsync_connectOptions conn_opts = MQTTAsync_connectOptions_initializer;
	MQTTAsync_disconnectOptions disc_opts = MQTTAsync_disconnectOptions_initializer;
	int rc;
	int ch;

	MQTTAsync_create(&client, ADDRESS, CLIENTID, MQTTCLIENT_PERSISTENCE_NONE, NULL);

	MQTTAsync_setCallbacks(client, client, connlost, msgarrvd, NULL);

	conn_opts.keepAliveInterval = 20;
	conn_opts.cleansession = 1;
	conn_opts.onSuccess = onConnect;
	conn_opts.onFailure = onConnectFailure;
	conn_opts.context = client;

    /* Start the connection process */
	if ((rc = MQTTAsync_connect(client, &conn_opts)) != MQTTASYNC_SUCCESS)
	{
		printf("Failed to start connect, return code %d\n", rc);
		exit(EXIT_FAILURE);
	}

    /* Wait until subscribed */
	while (!subscribed)
    {
        sleep(1);
    }

    /* Publish simple example message (without callbacks) */
    MQTTAsync_message pubmsg = MQTTAsync_message_initializer;
    pubmsg.payload = "test";
    pubmsg.payloadlen = strlen("test");
	printf("Publishing example message...\n");
    if ((rc = MQTTAsync_sendMessage(client, PUBLISH_TOPIC, &pubmsg, NULL)) != MQTTASYNC_SUCCESS)
    {
		printf("Failed to publish message, return code %d\n", rc);
		exit(EXIT_FAILURE);
    }

	if (finished)
    {
		goto exit;
    }

    /* Wait until user press Q to end the program */
	do 
	{
		ch = getchar();
	} while (ch!='Q' && ch != 'q');

    /* Disconnect client */
	disc_opts.onSuccess = onDisconnect;
	if ((rc = MQTTAsync_disconnect(client, &disc_opts)) != MQTTASYNC_SUCCESS)
	{
		printf("Failed to start disconnect, return code %d\n", rc);
		exit(EXIT_FAILURE);
	}
 	while (!disc_finished)
    {
	    sleep(1);
    }

exit:
	MQTTAsync_destroy(&client);
 	return rc;
}
