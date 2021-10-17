import requests as re
import json

baseurl = 'http://www.omdbapi.com/'
name = input("Enter Movie Name : ")
def id_extractor(movie):
    params_dict = {}
    params_dict['apikey'] = 'YOUR_API_KEY'
    params_dict['s'] = movie
    res = re.get(baseurl , params=params_dict)
    return res.json()['Search'][0]['imdbID']
params_dict = {}
params_dict['apikey'] = 'YOUR_API_KEY'
params_dict['i'] = id_extractor(name)
res = re.get(baseurl , params=params_dict)
page = res.json()
title = page['Title']
release_date = page['Released']
genre = page['Genre']
imdb_rating = page['imdbRating']
print('Title :\t'+title+'\nReleased:\t'+release_date+'\nGenre:\t'+genre+'\nIMDB_Rating:\t'+imdb_rating)
