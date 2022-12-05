from mediawiki import MediaWiki
import warnings
warnings.filterwarnings("ignore", category=UserWarning, module='bs4')
wikipedia = MediaWiki()
wikipedia.user_agent = 'my-new-user-agent-string'


with open('rtitles.txt', 'r', encoding='UTF-8') as r:
	with open('dank.txt', 'a', encoding='UTF-8') as f: 
		for title in r: 
			try: 
				p = wikipedia.page(title)
			except: 
				f.write("exception occured: " + title)
				f.write("\n")
			else:
				listofs = p.sections
				str = ""
				tlist1 = p.parse_section_links(None)
				if tlist1 != None: 
					for a in tlist1: 
						tt1 = a[0]
						if len(tt1) != 0: 
							if tt1[0] != '[' and tt1[0] != '/':
								str = str + a[1]
								str = str + ","
				for i in listofs: 
					if i == 'References':
						break
					if i == 'Citations':
						break
					tlist = p.parse_section_links(i)
					if tlist != None: 
						for j in tlist: 
							tt = j[0]
							if len(tt1) != 0: 
								if tt[0] != '[' and tt[0] != '/':
									str = str + j[1]
									str = str + ","
				f.write(title)
				f.write(str)
				f.write("\n")
	
