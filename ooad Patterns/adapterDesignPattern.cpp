#include <iostream>
using namespace std;
class Text {
private:
	string mytext;
public:
	Text(string someText) {
		this->mytext = someText;
	}
	string getText() {
		return this->mytext;
	}
	void setText(string someText) {
		this->mytext = someText;
	}
};

class TextToTranslate 
{
public:
	Text* getText() {
		return (new Text("This is your Untranslated Text."));
	}
};



//adapter i.e interface
class Translator {
public:
	virtual Text* getTextToTranslate() = 0;
	virtual Text* getTranslatedText() = 0;
};

class implementTranslator:public Translator {
	TextToTranslate* txt = new TextToTranslate();
public:
	Text* getTextToTranslate() {
		return txt->getText();
	}
	Text* getTranslatedText() {
		Text* t = txt->getText();
		cout <<t->getText()<<"\n";
		return new Text("This is your Translated Text.");
	}

};


int main() {

	Translator* translator = new implementTranslator();
	Text* t = translator->getTranslatedText();
	cout << t->getText();
	return 0;
}