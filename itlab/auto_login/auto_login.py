#!/usr/bin/python3

"""
    Installation commands
    Linux:
        pip3 install selenium (python3)
        pip install selenium (python2)

    Windows:
       Anaconda -> conda install -c conda-forge selenium
       Pyshell -> pip3 install selenium

    Selenium needs some of the webdrivers to be pre-installed, the links are provided below
    Firefox: https://github.com/mozilla/geckodriver/releases/download/v0.24.0/geckodriver-v0.24.0-linux64.tar.gz
    Chrome: https://sites.google.com/a/chromium.org/chromedriver/home

    Now you need to add the executable to the PATH, for this follow the below commands
    Linux:
        tar xvf <name-of-downloaded-zip-file>
        sudo cp <executable-file> /usr/bin

"""

import sys
import time

try:
    from selenium import webdriver
except:
    print("It seems you don't have a selenium module")
    print("Check the documentation for installation commands")
    sys.exit()

def auto_login(uname, password):
    try:
        driver = webdriver.Firefox()
        # driver = webdriver.Chrome()
    except:
        print("Drivers for firefox or chrome are not installed")
        print("Check the documentation for links")
        sys.exit()

    driver.get("http://192.168.56.2:8090")
    username = driver.find_element_by_id("username")
    passwd = driver.find_element_by_id("password")
    login = driver.find_element_by_id("loginbutton")

    username.send_keys(uname)
    passwd.send_keys(password)
    login.click()
    time.sleep(5)
    driver.close()
    driver.quit()

if __name__ == '__main__':
    uname = '17MCME13'
    passwd = 'cnf2017'

    auto_login(uname, passwd)
