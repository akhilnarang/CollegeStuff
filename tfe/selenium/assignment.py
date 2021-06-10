#!/usr/bin/env python3


from selenium import webdriver

query = input("Enter query to search for: ") or "tools for engineering"
number = int(input("Enter number of articles you want: ") or 3)

try:
    # Create chrome webdriver object
    driver = webdriver.Chrome()

    # Open google scholar website
    driver.get("https://scholar.google.com/")

    # Find the element for query, send in our query
    driver.find_element_by_id("gs_hdr_tsi").send_keys(query)

    # Find submit button by ID, and click it
    driver.find_element_by_id("gs_hdr_tsb").click()

    # Load articles since 2021
    driver.find_element_by_link_text("Since 2021").click()

    # Find article divs by class name
    article_divs = driver.find_elements_by_class_name("gs_ri")

    # Iterate through the given number of articles, and print links
    for article_div in article_divs[:number]:
        print(" - ", article_div.find_element_by_xpath("h3/a").get_property("href"))
except Exception as e:
    print("Exception occurred")
    print(e.message)
finally:
    driver.close()
