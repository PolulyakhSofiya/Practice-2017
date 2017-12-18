#include <string>
#include <iostream>

using namespace std;

struct template_value
{
	string name;
	string value;
};

template_value LikeASplit(string &values)
{
	template_value temp_values = {"", ""};
	string temp_char;
	bool isName = true;
	
	for (int i = 0; i < values.length(); i++)
	{
		temp_char = values[i];
		if (isName) 
			if (temp_char.compare(0, 1, "=") != 0)
				temp_values.name += temp_char;	
			else
				isName = false;			
		else
			if (temp_char.compare(0, 1, ",") != 0)
				temp_values.value += temp_char;
			else
				break;
	}
	
	if (values.find(",") && values.find(",") != string::npos)	
		values.erase(0, values.find(",") + 1);
	else
		values = "";

	return temp_values;
}

void ReplaceAllTemplates(string &user_template, template_value* templates, int length)
{
	user_template = " " + user_template;
	for (int i = 0; i < length; i++)
	{	
		string string_to_find = "[" + templates[i].name + "]";
		int index = user_template.find(string_to_find);
		
		while (index && index != string::npos)
		{
			user_template.replace((int)index, templates[i].name.length() + 2, templates[i].value);
			index = user_template.find(string_to_find);
		}
	}
}

void ApllyValueToTemplate(string values, string &user_template)
{
	int counter = 1;
	template_value *templates = new template_value[1];
	*templates = LikeASplit(values);
	
	while (values != "") {
		template_value* temp_vector = new template_value[++counter];
		
		for (int i = 0; i < counter -1; i++)
			temp_vector[i] = templates[i];
		
		temp_vector[counter - 1] = LikeASplit(values);
		
		delete [] templates;
		templates = temp_vector;
	}
	ReplaceAllTemplates(user_template, templates, counter);
}

int main()
{
	string values;
	getline(cin, values);
	
	string user_template;
	getline(cin, user_template);
	
	ApllyValueToTemplate(values, user_template);
	
	cout << user_template << "\n";
}