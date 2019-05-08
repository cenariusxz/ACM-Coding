
import re
import urllib

def getHtml(url):
	page = urllib.urlopen(url)
	html = page.read()
	return html

def getImg(html):
	reg = r'src="(.+?\.jpg)" pic_ext'
	imgre = re.compile(reg)
	imglist = re.findall(imgre,html)
	return imglist      

html = getHtml("https://tieba.baidu.com/p/3345056062")
print getImg(html)
