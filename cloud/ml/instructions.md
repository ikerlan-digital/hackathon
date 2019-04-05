# Machine Learning Task Instructions

* Develop a small program that saves historical data from influx into a csv. You can use this [trick](https://community.influxdata.com/t/export-daily-data-to-csv/2217/2).
* Use scikit learn to develop a machine learning model. Use the following command to install it ([help](https://scikit-learn.org/stable/install.html):
    * `sudo python3 -m pip install -U scikit-learn`
* Read data from the database and save it into a CSV file:
    * Query the database to get the data (install the corresponding [library](https://github.com/influxdata/influxdb-python)).
    * Pre-process the data as needed (check [Numpy](http://cs231n.github.io/python-numpy-tutorial/)).
    * Save the data into a CSV file (check [Pandas](https://www.tutorialspoint.com/python_pandas)).
    
* Generate a predictive model. It must forecast the next values of the time series.
    * Load data from the CSV file (Pandas).
    * Pre-process data, if required.
    * Select a machine learning algorithm suited for time series from scikit learn. Some examples:
        * ARIMA
        * ARMA
        * Up to you
    * Fire an alarm if the predicted value is higher than a given threshold.
    


# Instrucciones para la tarea de Machine Learning
* Desarrollar un pequeño programa que guarde en un fichero CSV el histórico de datos almacenado en influx. Podeis usar este [consejo](https://community.influxdata.com/t/export-daily-data-to-csv/2217/2).
* Usad sckit learn para generar un modelo predictivo mediante técnicas de machine learning. Usad el siguiente comando para instalarlo ([ayuda](https://scikit-learn.org/stable/install.html)):
    * `sudo python3 -m pip install -U scikit-learn`
* Leed los datos de la base de datos i guardadlo en un fichero CSV:
    * Haced una consulta SQL para leer los datos de la base de datos (instalad la correspondiente [librería](https://github.com/influxdata/influxdb-python)))
    * Pre-procesad los datos, en caso necesario (mirad [Numpy](http://cs231n.github.io/python-numpy-tutorial/)).
    * Guardad los datos en un fichero CSV (mirad [Pandas](https://www.tutorialspoint.com/python_pandas)).
* Generad un modelo predictivo. Este modelo deberá predecir los siguientes variables de la serie temporal:
    * Cargad los datos desde el fichero CSV (Pandas).
    * Pre-procesad los datos, en caso necesario.
    * Seleccionad un algoritmo de machine learning, orientado a series temporales, de scikit learn. Algunos ejemplos:
        * ARIMA
        * ARMA
        * A tu libre elección
    * Lanzar una alarma en caso de que el valor predecido supere un umbral predeterminado.
    
    
