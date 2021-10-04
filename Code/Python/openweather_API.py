##--> Importing Useful Libraries
import requests as re   ##--> Request module to request URL from web
import json             ##--> To read json formatted data from web 


def weather():          ##--> method of extracting weather detail from openweathermap API 
    baseurl = 'https://api.openweathermap.org/data/2.5/weather'
    params_dict = {}
    params_dict["APPID"] = 'your-APPID'   ##--> Visit openweathermap.org to create APPID and access its data 
    #params_dict['zip'] = input("Enter City")  --by zip code
    #params_dict['q'] = input("Enter City Name : \t")
    params_dict['q'] = "Ranip"            ##--> Manually Replace your desirede city from all over world
    res = re.get(baseurl, params=params_dict)
    page = res.json()
    #print(page)
    weather_type = page['weather'][0]['description']
    #print(weather_type)
    temp_c = page['main']['temp'] - 273.15
    #print(temp_c)
    feels_like = page['main']['feels_like'] - 273.15
    #print(feels_like)
    humidity = page['main']['humidity']
    #print(humidity)
    wind_speed = page['wind']['speed']
    #print(wind_speed)
    '''print("City:\t\t", page['name'])
    print("Weather_type:\t", weather_type)
    print("Temperature(C):\t", temp_c)
    print("Feels_like(C):\t", feels_like)
    print("Humidity:\t", humidity)
    print("Wind_Speed(Km'\'hr):", wind_speed)'''
    return page['name'], weather_type, temp_c, feels_like, humidity, wind_speed
weather()
