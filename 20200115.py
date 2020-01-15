import webbrowser
import requests

'''
webbrowser.open("https://www.google.com")
webbrowser.open_new(주소)
webbrowser.open_new_tab(주소)
'''

''' list를 사용해서 여러 tab 띄우기 '''
address = "https://search.naver.com/search.naver?sm=top_hty&fbm=1&ie=utf8&query="
add_list = ["ssafy","싸피","검색"]
for i in range(len(add_list)):
    search = address+add_list[i]
    webbrowser.open(search)

