#!/usr/bin/python3

import os

try:
    from selenium import webdriver
except:
    os.system("./install.py")

driver = webdriver.Firefox()
"""driver.get('https://www.linkedin.com/login')
username = driver.find_element_by_id("username")
username.send_keys('anurag.peddi1998@gmail.com')
passwd = driver.find_element_by_id('password')
passwd.send_keys('Rag@1998')

log_in_button = driver.find_element_by_class_name("btn__primary--large.from__button--floating")
log_in_button.click()"""

driver.get("https://www.google.com/")
search_query = driver.find_element_by_name("q")
search_query.send_keys('site:linkedin.com/in/ AND "UOH" AND "SCIS"')
search_query.submit()
"""search_query.send_keys(Keys.RETURN)
driver.find_element_by_name("btnK").click()"""

