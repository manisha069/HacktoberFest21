import pyttsx3
import datetime
import speech_recognition as sr
import wikipedia
import webbrowser

'''
this will create a variable sound that'll store the sapi5
in it.and them we'll dump the voices in the sound and set it's voice to 
be male or female.
'''
sound = pyttsx3.init('sapi5')
voice = sound.getProperty('voices')
sound.setProperty('voice',voice[0].id)

def speak(audio):
    sound.say(audio)
    sound.runAndWait()
    
def greeting():
    time = int(datetime.datetime.now().hour)
    if time > 0 and time < 12:
        speak("GOOD MORNING,SIR...")
    
    elif time >= 12 and time < 18:
        speak("GOOD AFTERNOON,SIR...")
        
    else:
        speak("GOOD NIGHT,SIR...")


'''
function to listen and passing the input as sound and givingan output in the form of
sound/string.
'''
def recognizing():
    #it takes speech as input from the microphone and gives a stingas an output
    
    recog = sr.Recognizer() #cretes a recognizer instance 
    with sr.Microphone() as source: #creates a microphne instance on the the system as sourece
        print("LISTENING.........")
        recog.pause_threshold = 1 #seconds of non-speaking audio before a phrase is considered complete
        recog.energy_threshold = 200
        sound = recog.listen(source) #listen a single word
        
    try:
        print("RECOGNIZING........")
        #sends the recognized voice to the google ass. API for clarification takes input the voice and language
        doubt = recog.recognize_google(sound, language = 'en - in')
        print(f"USER SAID : {doubt}\n")
        
    except Exception as e:
        print("SAY THAT AGAIN PLASE..........")
        return "NONE"
    
    return doubt

def open(search):
    if 'open ' in search:
        search = search.replace("open","")
        webbrowser.open(f"{search}.com")
    
    

if __name__ == "__main__":
    greeting()
    speak("My name is Jarvis!WHAT CAN I DO FOR YOU ,SIR?")
    while True:
        
        doubt = recognizing().lower()
        
        if 'wikipedia' in doubt:
            speak("SCRAPPING THE WIKIPEDIA.....")
            doubt = doubt.replace("wikipedia","")
            results = wikipedia.summary(doubt, sentences = 2)
            speak("ACCORDING TO WIKIPEDIA...")
            print(results)
            speak(results)
            
        '''elif 'open ' in doubt:
            doubt = doubt.replace("open","")
            open(doubt)
            '''
        
        
        open(doubt)
        

