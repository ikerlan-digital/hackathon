import serial

if __name__ == "__main__":
    with serial.Serial('/dev/ttyS0', 9600, timeout=1) as ser:
        data = ser.read(200)
        print(data.hex())
        ser.close()
