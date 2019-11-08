#!/usr/bin/python3

from selenium import webdriver

browser = webdriver.Firefox()
browser.get("http://scis.uohyd.ac.in/People/Student/index.php")

a_tags = browser.find_elements_by_class_name("trans_current")

alumni = list()

for tag in a_tags:
    for year in range(2000, 2020):
        if tag.text.endswith(str(year)):
            alumni.append(tag.get_attribute("href"))

names = list()
for link in alumni:
    browser.get(link)
    td_tags = browser.find_elements_by_tag_name("td")
    for value in td_tags:
        names.append(value.text)

print("Alumni names of SCIS: ")
for name in names:
    found = False
    for num in range(10):
        if str(num) in name:
            found = True
            break
    if not found:
        print(name)
browser.quit()
