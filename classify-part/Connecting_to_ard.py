# import IPython.display as ipd
import numpy as np
import librosa
#import librosa.display
# from IPython.display import display, Image

import sounddevice as sd
import numpy as np
from scipy.io.wavfile import write
import tempfile
import os

#library for arduino connectivity
import serial.tools.list_ports

def record_audio(duration=10, sample_rate=44100):
    # Initialize the sounddevice input stream
    input_stream = sd.InputStream(channels=1, samplerate=sample_rate, dtype=np.int16)

    # Create a temporary file to store the recorded audio
    temp_wav_file = tempfile.NamedTemporaryFile(suffix=".wav", delete=False)
    temp_wav_file.close()

    # Start the input stream
    input_stream.start()

    print("Recording...")
    # Record audio for the specified duration
    audio_data, _ = input_stream.read(int(duration * sample_rate))
    input_stream.stop()

    print("Recording complete")

    # Save the recorded audio to the temporary WAV file
    write(temp_wav_file.name, sample_rate, audio_data)

    return temp_wav_file.name


def get_frequency(audio_file):
    y, sr = librosa.load(audio_file)
    spectrum = np.abs(librosa.stft(y))
    average_spectrum = np.mean(spectrum, axis=1)
    frequencies = librosa.fft_frequencies(sr=sr)
    dominant_frequency = frequencies[np.argmax(average_spectrum)]
    return dominant_frequency

    
def identify_sound(audio_file):
    frequency = get_frequency(audio_file)
    
    mobile = [2347.119140625, 2637.8173828125, 3326.8798828125, 3520.6787109375]
    alarm = [645.99609375, 1948.7548828125,3251.513671875]
    doorbell = [1830.322265625,1012.060546875, 1162.79296875, 1248.92578125]
    beep = [1001.2939453125, 2993.115234375]
    dog = [538.330078125, 979.7607421875, 990.52734375, 1216.6259765625, 1388.8916015625]
    cooker = 3305.3466796875 or 2314.8193359375
    
    if frequency in mobile:
        return "mobile ringtone"
    elif frequency in alarm:
        return "alarm sound"
    elif frequency in doorbell:
        return "doorbell"
    elif frequency in beep:
        return "beep sound"
    elif frequency in dog:
        return "dog barking"
    elif cooker==frequency:
        return "cooker whistle"
    return "Unknown Sound"

audio_file = record_audio(duration=10)
result = identify_sound(audio_file)
print("Identified Sound:", result)

'''---- Arduino connectivity part------------'''

ports = serial.tools.list_ports.comports()
serialInst = serial.Serial()
portList = []

for each in ports :
    portList.append(str(each))
    print(str(each))

print(portList)


com = input("Select COM Port for Arduino :-  ")

for i in range(len(portList)):
    if portList[i].startswith("COM" + str(com)):
        use = "COM" + str(com)
        print(use)

serialInst.baudrate = 9600
serialInst.port = use
serialInst.open()

while True:
    # command = input("Arduino command ON/OFF/exit : ")
    command = result
    serialInst.write(command.encode('utf-8'))
    
    if command == 'exit' :
        exit()


