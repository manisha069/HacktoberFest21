# Importing Libraries
from requests_html import HTMLSession
from bs4 import BeautifulSoup
import sqlite3


s = HTMLSession()
baseurl = "https://www.amazon.in"
search_item = input("What item (Use + for spaces): ") # Product Name
page_no = int(input("Till how many pages : "))        # Number of Pages you want to extract


# Method for get data from Amazon
def get_data(search_item, page_no):
    url = f"https://www.amazon.in/s?k={search_item}&page={page_no}"
    r = s.get(url)
    r.html.render(sleep = 1)
    soup = BeautifulSoup(r.html.html, 'html.parser')
    return soup


# Method to store in local database
def store_in_db(title, price, link, rating, review):

    # Making databse as name of search
    database_path = f"{search_item}.db"

    conn = sqlite3.Connection(database_path)
    c = conn.cursor()

    #c.execute(f'DROP TABLE IF EXISTS {database_path}')
    c.execute(f'''CREATE TABLE IF NOT EXISTS {search_item.split('+')[0].lower()} (name text, price text,
               link text, rating real, reviews real)''')

    # Insert a row of data
    insert_query = f"INSERT OR IGNORE INTO {search_item.split('+')[0].lower()} VALUES (?, ?, ?, ?, ?)"
    c.execute(insert_query, (title, price, link, rating, review))

    conn.commit()
    conn.close()


# Method to get all details of desired product
def get_details(soup):
    names, links, prices, ratings, reviews = [], [], [], [], []
    products = soup.find_all('div', {'data-component-type' : 's-search-result'})
    for item in products:
        link = item.find('a', {'class' : 'a-link-normal a-text-normal'})['href']
        name = item.find('a', {'class' : 'a-link-normal a-text-normal'}).text.strip()

        try:
            price = float(item.find('span', {'class' : 'a-offscreen'}).text.replace('₹','').replace(',',''))
        except:
            price = 00

        try:
            rating = item.find('span', {'class' : "a-icon-alt"}).text.strip()
        except:
            rating = 0

        try:
            review = item.find('span', {'class' : 'a-size-base'}).text.strip()
        except:
            review = 0

        # Now let's store details into our local sqlite database
        store_in_db(name, price, baseurl + link, rating, review)

        # To make Dict let's make lists of Product details
        names.append(name)
        links.append(baseurl+link)
        prices.append(price)
        ratings.append(rating)
        reviews.append(review)

    # Let's make dictionary if in future we want to make DataFrame
    product_item = {
        'title' : names,
        'price' : prices,
        'link' : links,
        'ratings' : ratings,
        'reviews' : reviews
    }
    return product_item


def main():
    i = 1 # To iterate through pages    
    while i <= page_no:
        deal = get_details(get_data(search_item, i))
        print(f"Completed page number : {i}")
        i += 1
    print("Finished, Please check Database file")
    #print(deal) # To print Dict of data


main()
