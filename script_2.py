import serial
import time

PORT = '/dev/ttyUSB0'
BAUD = 9600

ser = serial.Serial(PORT, BAUD, timeout=5)
time.sleep(2)  # wait for Arduino to finish resetting
def readNextLine():
    while(True):
        line = ser.readline().decode('utf-8').strip()
        if line:
            break
    return line

def forceTest():
    line = readNextLine()
    randomNumber = float(line)
    print("  ==== Force Test ====  ")
    print(f"apply {randomNumber} newtons on the hook")
    line = readNextLine()
    error = float(line)
    print(f"you were off by {error} newtons")


def DistanceTest():
    line = readNextLine()
    randomNum = float(line)
    print("  ==== Distance Test ====   ")
    print(f"Raise your hand to this distance: {randomNum} cm.")
    print("You have 5 seconds...")
    line = readNextLine()
    print(line)



def ReactionTest():
    print("  ==== Reaction Time Test ====  ")
    print("Put your hand on the sensor when the green LED lights up..")
    reflexLine = readNextLine() #line1 hya5d el Reflex time
    print(reflexLine) 
    print(readNextLine()) #hy3rd el station1_finished


while True:
    line = readNextLine()
    if line == 'StartForceTest':
        forceTest()
    elif line == 'StartDistanceTest':
        DistanceTest()
    elif line == 'StartReactionTest':
        ReactionTest()
                
