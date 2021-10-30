#include <iostream>
#include <fstream>
#include <string>



//g++ main.cpp -o floppa

enum Tokentype
{
	Number,
	Var,
	Star,
	Minus,
	Shlesh,
	Plus,
	Foonction,
	IF,
	ELSE,
	Empty,
	Endstr
};

struct Token
{
	std::string text;
	Tokentype type;

	Token(std::string text,Tokentype type)
	{
		this->text=text;
		this->type=type;
	}
	Token()
	{
		this->text=' ';
		this->type=Empty;		
	}
};

int main()
{
	setlocale(LC_ALL, "Ru");
	std::string path = "code.floppascript";


	std::string code = " ";
	std::string str = " ";

	std::ifstream filecode;
	filecode.open(path);

	if (!filecode.is_open())
	{
		std::cout << "error open file!\n";
	}
	else
	{
		while(!filecode.eof())
		{
			str = "";
			std::getline(filecode,str);
			code += str+"\n";
		}
	}


	std::string lens=code;


    std::cout<<lens<<std::endl;
    


	filecode.close();

	int PositionTokenRead=0;
	int tokenscount=0;
	int i = 0;

	Token *Tokens;

	for(int i = 0;i<lens.length();i++)
	{
		if(lens[i]==';')
		{
			tokenscount++;
		}
	}
	tokenscount--;

	const int commandcount=1;
	std::string commands[commandcount];
	commands[0]="Print";

	Tokens=new Token[tokenscount];

	std::cout<<"\n"<<tokenscount<<"\n\n";
	
	for(int i = 0;i<lens.length();i++)
	{
		std::string token=" ";
		int endstring=0;

		if(lens[i]!=';')
		{
			token[i]=lens[i];
		}
		else
		{
			endstring=i;
		}
		for(int j = 0;j<commandcount;j++)
		{
			if(j==0)
			{
				std::cout<<"\nDebug\n";
				int indexend=0;
				bool nocommand=false;
				std::string command=commands[0];
				for(int y = 0;y<command.length();y++)
				{
					if(token[y]!=command[y])
					{
						nocommand=true;
						break;
					}
				}
				std::cout<<"\nDebug\n";
				if(!nocommand)
				{
					indexend=command.length();
					int indexotskobki,indexzakskobki,
					indexotkovich,indexzakkovich;
					int count=4;
					std::cout<<"\nDebug\n";

					for(int k=endstring;k<indexend;k++)
					{
						if(lens[k]=='(')
						{
							indexotskobki=k;
							count--;
						}
						if(lens[k]=='"')
						{
							indexotkovich=k;
							count--;
							k++;
						}
						if(lens[k]=='"')
						{
							indexzakkovich=k;
							count--;
						}
						if(lens[k]==')')
						{
							indexzakskobki=k;
							count--;
						}
						if(count==0)
							break;
						std::cout<<"\nDebug\n";
					}

/*
					if(count>0)
					{
						std::cout<<"error str: " << indexend << std::endl;
					}
					std::cout<<"";
					*/
					std::cout<<"\nDebug\n";
				}

			}
		}
		

	}	

    system("pause");
}

