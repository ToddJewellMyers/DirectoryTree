//Todd J Myers

#include <iostream>
#include <string>
#include "Tree.h"

using namespace std;



int main()
{
	string userinput;
	Tree tree;

	while (userinput.compare("quit") != 0)
	{

		cout << "Enter a command: ";
		getline(cin, userinput);

		//pwd command
		//Time complexity: O(N)
		if (userinput.compare("pwd") == 0)
		{
			cout << tree.pointer->name << endl;
			continue;
		}

		//ls command
		//Time complexity: O(N) where N is the number of children of the directory
		else if (userinput.compare("ls") == 0)
		{
			if (tree.pointer->children.empty() == true)
			{
				cout << "This directory is empty" << endl;
			}
			else 
			{
				tree.printchildren(tree.pointer);
			}
			continue;
		}

		//exists command
		//Time complexity: O(N)
		else if (userinput.compare(0,6,"exists") == 0)
		{
			userinput.erase(0,7);
			if (tree.exists(userinput) == true) 
			{
				cout << userinput + " exists" << endl;
			}
			else 
			{
				cout << userinput + " does not exist" << endl;
			}
			continue;
		}

		//cd .. command
		//Time complexity: O(1)
		else if (userinput.compare("cd ..") == 0) 
		{
			if (tree.pointer->parent == NULL) 
			{
				cout << "You are in the root directory" << endl;
			}
			else
			{
				tree.pointer = tree.pointer->parent;
			}
			continue;
		}

		//cd command
		//Time complexity: O(N) where N is the number of children of the directory
		else if (userinput.compare(0,2,"cd") == 0)
		{
			bool dirfound = false;
			userinput.erase(0,3);
			for (int i = 0; i < tree.pointer->children.size(); i++) 
			{
				if (tree.pointer->children[i]->name.compare(userinput) == 0) 
				{
					tree.pointer = tree.pointer->children[i];
					dirfound = true;
					break;
				}
			}

			if (dirfound == false)
			{
				cout << userinput << " not found" << endl;
			}
			continue;
		}

		//mkdir command
		//Time complexity: O(1)
		else if (userinput.compare(0,5,"mkdir") == 0)
		{
			userinput.erase(0, 6);
			tree.insert(userinput);
			continue;
		}

		//rmdir command
		//Time complexity: O(N) where N is the number of children of the directory
		else if (userinput.compare(0,5,"rmdir") == 0)
		{
			bool dirfound = false;
			userinput.erase(0,6);
			for (int i = 0; i < tree.pointer->children.size(); i++) 
			{
				if (tree.pointer->children[i]->name.compare(userinput) == 0) 
				{
					
					//remove found child and all children of it
					//tree.remove(tree.pointer->children[i]);
					tree.pointer->children.erase(tree.pointer->children.begin() + i);

					dirfound = true;
					break;
				}
			}

			if (dirfound == false) 
			{
				cout << userinput << " not found" << endl;
			}
			continue;
		}
		
		//countdir command
		//Time complexity: O(N) where N is the number of subdirectories of the current directory + 1
		else if (userinput.compare("countdir") == 0) 
		{
			cout << tree.count(tree.pointer) << endl;
			continue;
		}

		//showtree command
		//Time complexity: O(N) where N is the current directory + all subdirectories
		else if (userinput.compare("showtree") == 0)
		{
			tree.showtree(tree.pointer);
			continue;
		}

		else if (userinput.compare("quit") == 0) 
		{
			break;
		}

		else 
		{
			cout << "Unknown command" << endl;
		}
	}
}
