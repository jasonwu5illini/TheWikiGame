#takes an hour to generate file with 1667 articles, need to make new line on last title manually
from mediawiki import MediaWiki
import warnings
warnings.filterwarnings("ignore", category=UserWarning, module='bs4') #suppress warnings that show up when urls are parsed
wikipedia = MediaWiki()
wikipedia.user_agent = 'my-new-user-agent-string'


with open('input.txt', 'r', encoding='UTF-8') as r: #open input with read operation
	with open('output.txt', 'a', encoding='UTF-8') as f:  #open output with append operation
		for title in r: 
			try: 
				p = wikipedia.page(title) #try getting a page with the library by title 
			except: 
				f.write("exception occured: " + title) #if it doesn't work write exception occured and move on, article can be deleted later as part of data cleaning 
				f.write("\n")
			else:
				listofs = p.sections #get list of sections of the article
				str = ""
				tlist1 = p.parse_section_links(None) #get links between header and first section
				if tlist1 != None:  
					for a in tlist1: 
						tt1 = a[0]
						if len(tt1) != 0: 
							if tt1[0] != '[' and tt1[0] != '/': #get rid of irrelevant urls [ means citation and / usually means picture
								str = str + a[1] # append url 
								str = str + ","
				for i in listofs: #go through each section
					if i == 'References':
						break
					if i == 'Citations': #stop when you hit references or citations, sections after that don't count per wikigame rules
						break
					tlist = p.parse_section_links(i) # same process as above
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
	
