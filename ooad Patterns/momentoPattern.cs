/*

~ This momento pattern is performed for undo functionality.
-------What is in MOMENTO Pattern?
  - aik momento ki class bnai jis me hr us datatype ka attribute bnaya jis tarha ka data editor me likha jana aur un sb k getter/setter bna diye.
  - aik history ki class bnai jis me editor me likhi janay wali hr new text 
    ko sath sath push kia gaya aur undo krny pe pop b kia gaya.
  - aik editor ki class bnai jis me jb jb data write ho ga us ko momento bna k history
    me push kia jaye ga aur jb jb data undo ho ga us ko momento bna k restore kia jaye ga.
*/


//EditorStates = Momento
//Editor = Originator
//History = Caretaker


using System;
using System.Collections.Generic;

namespace momentoFinalPattern
{
	//momento class => This is the class which will contain all the type of data which can be stored in your editor either it is string or char or int etc.
	class momento
	{
		private string con;
		//if any integer you want in editor, then make its attribute here too.

		//constructor
		public momento(string content)
		{
			this.con = content;
		}
		//getter
		public string getCon()
		{
			return con;
		}
	};

	// Editor class => This class will take the reference of momento class.
	class originator
	{

		private string content;
		//if any integer you want in editor, then make its attribute here too.

		//getter/setter
		public void setContent(string content)
		{
			this.content = content;
		}
		public string getContent()
		{
			return content;
		}

		public momento createState()  //this function will make your content ready for to be pushed in history(momento).         
		{
			return (new momento(content));
		}

		//read content through momento
		public void restore(momento m)    //this function will make you momento, content.
		{
			content = m.getCon();
		}
	};

	//composition => history class is composed of momento class. This class will add & remove data(momento) in your list.
	class history
	{
		private List<momento> l = new List<momento>();
		public void push(momento content)
		{
			l.Add(content);
		}
		public momento pop()
		{
			int lastIndex = l.Count - 1;
			momento content = l[lastIndex - 1];
			l.RemoveAt(lastIndex - 1);
			return content;
		}
	};

	//main
	class Program
	{
		static void Main(string[] args)
		{
			originator o = new originator();
			history h = new history();

			o.setContent("a");            //content is written in editor.  
			h.push(o.createState());     //make the momento of your content and save it in history

			o.setContent("b");
			h.push(o.createState());

			o.setContent("c");
			h.push(o.createState());
			o.restore(h.pop());                     //undo functionality
			Console.WriteLine(o.getContent());    //b because c is removed.

			o.setContent("d");
			h.push(o.createState());

			o.setContent("e");
			h.push(o.createState());
			o.restore(h.pop());                    //undo functionality
			Console.WriteLine(o.getContent());    //d because e is removed
		}
	}
}
