import serial
import time

def serial_Setup():
	baudrate = 9600
	timeout = 3
	port = "/dev/tty.usbserial-A9C3J9LH"
	return serial.Serial (port, baudrate, timeout = timeout)

def serial_Listen(ser):
	try:
		line = ser.readline()
	except ser.SerialTimeoutException:
		print('Timeout! Data could not be read!')
	return line

#def serial_Decoder(line_received):


ser = serial_Setup ()
while 1:
	data = serial_Listen (ser)
	print (data)

# ser = serial.Serial('/dev/tty.usbmodem1421', 9600, timeout= 1)
 
# while 1:
#  try:
#   x = ser.readline()
#   #time.sleep(1)
#   print (x)
#   time.sleep(0.01)
#  except ser.SerialTimeoutException:
#   print('Data could not be read')
