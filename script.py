
from mediawiki import MediaWiki
wikipedia = MediaWiki()
wikipedia.user_agent = 'my-new-user-agent-string'

r = open('rtitles.txt', 'r', encoding='UTF-8') 
f = open('output.txt', 'a', encoding='UTF-8') 
with open('rtitles.txt', 'r', encoding='UTF-8') as r:
	with open('output.txt', 'a', encoding='UTF-8') as f: 
		for title in r: 
			try: 
				p = wikipedia.page(title)
			except: 
				f.write("exception occured: " + title)
				f.write("\n")
			else:
				list = p.links 
				str = ",".join(list)
				f.write(title)
				f.write(str)
				f.write("\n")