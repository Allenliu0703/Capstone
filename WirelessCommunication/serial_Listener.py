import serial
import time

def serial_Setup():
	baudrate = 9600
	timeout = 3
	port = "/dev/tty.usbserial-A50285BI"
	return serial.Serial (port, baudrate, timeout = timeout)

def serial_Listen(ser):
	try:
		line = ser.readline()
	except ser.SerialTimeoutException:
		print('Timeout! Data could not be read!')
	return line.decode("utf-8")

def serial_Decoder(line_received):
	data_array = line_received.split()
	if not data_array:
		# print('Data not received :( Data array is empty')
		# break
		pass
	else:
		data_x = int(data_array[0][2:])
		data_y = int(data_array[1][2:])
		data_array = [data_x,data_y]
		#print(data_array)
	return data_array

ser = serial_Setup ()
while 1:
	data = serial_Listen (ser)
	# print(data)
	location_data = serial_Decoder(data)
	# print(location_data)
	if not location_data:
		print('Data not received :( Data array is empty')
	else:
		ser.write("X value is received as " + (str)(location_data[0]) + " Y value is received as " + (str)(location_data[1]))
		print ("X value is received as " + (str)(location_data[0]) + " Y value is received as " + (str)(location_data[1]))




# ser = serial.Serial('/dev/tty.usbmodem1421', 9600, timeout= 1)
 
# while 1:
#  try:
#   x = ser.readline()
#   #time.sleep(1)
#   print (x)
#   time.sleep(0.01)
#  except ser.SerialTimeoutException:
#   print('Data could not be read')
