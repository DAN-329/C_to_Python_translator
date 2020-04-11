#include<stdio.h>
#include<string.h>
void header(char a[200][100],int *num)
{
    int i;
    int n=*num;
    char t[50];
    for(i=0;i<n;i++)
    {
       	if(strcmp(a[i],"#include<stdio.h>")==0)
        {
            for(int k=i;k<n;k++)
                strcpy(a[k],a[k+1]);
            n--;
            i--;
        }
        else if(strcmp(a[i],"#include<string.h>")==0)
            strcpy(a[i],"import string");
        else if(strcmp(a[i],"#include<math.h>")==0)
            strcpy(a[i],"import math");
        else if(strcmp(a[i],"return 0;")==0 || strcmp(a[i],"\treturn 0;")==0 ||strcmp(a[i],"int main()")==0 || strcmp(a[i],"{")==0 || strcmp(a[i],"}")==0 ||strcmp(a[i],"end")==0 || strcmp(a[i],"\t{")==0 || strcmp(a[i],"\t}")==0 || strcmp(a[i],"\t\t{")==0 || strcmp(a[i],"\t\t}")==0 || strcmp(a[i],"\tbreak;")==0 || strcmp(a[i],"\t\tbreak;")==0 || strcmp(a[i],"\t\t\tbreak;")==0|| strncmp(a[i],"\t}",2)==0 || strncmp(a[i],"\t{",2)==0)
        {
            for(int k=i;k<n;k++)
                strcpy(a[k],a[k+1]);
            n--;
            i--;
        }
        else if(strcmp(a[i],"\t\t\t{")==0 || strcmp(a[i],"\t\t\t}")==0 || strcmp(a[i],"\t\t\t\t{")==0 || strcmp(a[i],"\t\t\t\t}")==0 || strcmp(a[i],"\t\t\t\t\t{")==0 || strcmp(a[i],"\t\t\t\t\t}")==0)
        {
            for(int k=i;k<n;k++)
                strcpy(a[k],a[k+1]);
            n--;
            i--;
        }
    }
    *num=n;
}
void semi(char a[200][100],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a[i][strlen(a[i])-1]==';')
            a[i][strlen(a[i])-1]='\0';
    }

}
void scan(char a[200][100],int *num)//handles scanf().
{
    for(int i=0;i<*num;i++)
    {
        int j,k=0,flag=0,u=0,supp=0;
        char var[10][100];
        char supp1[]={"\t"},supp2[]={"\t\t"},supp3[]={"\t\t\t"};
        char arr[40];
        if(strncmp(a[i],"scanf",5)==0|| strncmp(a[i],"\tscanf",6)==0||strncmp(a[i],"\t\tscanf",7)==0||strncmp(a[i],"\t\t\tscanf",8)==0)
        {
            if(strncmp(a[i],"\tscanf",6)==0)
                supp=1;
             else if(strncmp(a[i],"\t\tscanf",7)==0)
                supp=2;
             else if(strncmp(a[i],"\t\t\tscanf",8)==0)
                supp=3;
             else
                supp=0;
             for(j=10+supp;j<strlen(a[i]);j++)
             {
                 int loc=0;
                 if(a[i][j]=='&')
                 {
                    while(a[i][j]!=')')
                    {
                     var[k][loc]=a[i][j+1];
                     loc++;
                     j++;
                    }
                     var[k][loc-1]='\0';
                     k=k+1;
                 }

             }
             strcpy(arr,a[i]);
             for(j=8+supp;j<strlen(arr);j+=1)
             {
                    char temp[100];
                    if(arr[i]=='&')
                        break;
                    if(k>=1)
                    {
                       switch(arr[j])
                       {
                            case 'd':strcpy(temp,strcat(var[u],"=int(input())"));
                                    if(supp==1)
                                    {
                                        strcpy(a[i],strcat(supp1,temp));
                                    }

                                    else if(supp==2)
                                    {
                                        strcpy(a[i],strcat(supp2,temp));
                                    }

                                    else if(supp==3)
                                    {
                                        strcpy(a[i],strcat(supp3,temp));
                                    }

                                    else
                                    {
                                         strcpy(a[i],temp);
                                    }
                                    u++;
                                    flag=1;
                                    k--;
                                    break;
                            case 'f':strcpy(temp,strcat(var[u],"=float(input())"));
                                    if(supp==1)
                                    {
                                        strcpy(a[i],strcat(supp1,temp));
                                    }

                                    else if(supp==2)
                                    {
                                        strcpy(a[i],strcat(supp2,temp));
                                    }

                                    else if(supp==3)
                                    {
                                        strcpy(a[i],strcat(supp3,temp));
                                    }

                                    else
                                    {
                                         strcpy(a[i],temp);
                                    }
                                    u++;
                                    flag=1;
                                    k--;
                                    break;
                            case 'c':strcpy(temp,strcat(var[u],"=input()"));
                                    if(supp==1)
                                    {
                                        strcpy(a[i],strcat(supp1,temp));
                                    }

                                    else if(supp==2)
                                    {
                                        strcpy(a[i],strcat(supp2,temp));
                                    }

                                    else if(supp==3)
                                    {
                                        strcpy(a[i],strcat(supp3,temp));
                                    }

                                    else
                                    {
                                         strcpy(a[i],temp);
                                    }
                                    u++;
                                    flag=1;
                                    k--;
                                    break;
                            case 's':strcpy(temp,strcat(var[u],"=input()"));
                                    if(supp==1)
                                    {
                                        strcpy(a[i],strcat(supp1,temp));
                                    }

                                    else if(supp==2)
                                    {
                                        strcpy(a[i],strcat(supp2,temp));
                                    }

                                    else if(supp==3)
                                    {
                                        strcpy(a[i],strcat(supp3,temp));
                                    }

                                    else
                                    {
                                         strcpy(a[i],temp);
                                    }
                                    u++;
                                    flag=1;
                                    k--;
                                    break;

                            default:break;
                        }
                        if(flag==1)
                            break;

                   }
             }
        }
    }
}
void pri(char a[200][100],int *num)//handles removal of '\t if necessary
{
    int n=*num,i,flag=0;
    for(i=0;i<n;i++)
    {
        if(strcmp(a[i],"int main()")==0)
        {
            for(int g=i;g<n;g++)
            {
                for(int j=0;j<strlen(a[g]);j++)//used for removing the first \t in the program
                {
                    if(strncmp(a[g],"\tcase",5)==0 || strncmp(a[g],"\t\tcase",6)==0 || strncmp(a[g],"\t\t\tcase",7)==0 || strncmp(a[g],"\tdefault",8)==0 || strncmp(a[g],"\t\tdefault",9)==0)
                    {
                        g=g+1;
                    }
                    else if(a[g][j]=='\t')
                    {
                        for(int k=j;k<strlen(a[g]);k++)
                            a[g][k]=a[g][k+1];
                    }
                }
            }
            flag=1;
        }
        if(flag==1)
            break;
    }
}
void whiledo(char a[200][100],int *num)//handles while,do while also handles -i++,i-- only not ++i.
{
    int n=*num,i;
    for(i=0;i<n;i++)
    {
        int len,flag=0,app=0;
        char temp;
        char var[20];
        if(strncmp(a[i],"while",5)==0 || strncmp(a[i],"\twhile",6)==0 || strncmp(a[i],"\t\twhile",7)==0 || strncmp(a[i],"\t\t\twhile",8)==0 ||strncmp(a[i],"\t\t\t\twhile",9)==0)//for while loop
        {

            len=strlen(a[i]);
            a[i][len]=':';
            a[i][len+1]='\0';
        }
        for(int j=0;j<strlen(a[i]);j++)// for i++,i--
        {
            if(a[i][j]=='+' && a[i][j+1]=='+')
            {
                a[i][j+1]='=';
                for(int k=strlen(a[i]);k>j+2;k--)
                {
                        a[i][k]=a[i][k-1];

                }
                a[i][j+2]='1';
            }
            if(a[i][j]=='-' && a[i][j+1]=='-')
            {
                a[i][j+1]='=';
                for(int k=strlen(a[i]);k>j+2;k--)
                {
                        a[i][k]=a[i][k-1];

                }
                a[i][j+2]='1';
            }
        }
        if(strncmp(a[i],"}while",6)==0)// for do while loop
        {
            flag=1;
            app=0;
        }
        else if(strncmp(a[i],"\t}while",7)==0)
        {
            flag=1;
            app=1;
        }
        else if(strncmp(a[i],"\t\t}while",8)==0)
        {
            flag=1;
            app=2;
        }
        else if(strncmp(a[i],"\t\t\t}while",9)==0)
        {
            flag=1;
            app=3;
        }
         else if(strncmp(a[i],"\t\t\t\t}while",9)==0)
        {
            flag=1;
            app=4;
        }
        if(flag==1)
        {
            char t1[]={"\t"},t2[]={"\t\t"},t3[]={"\t\t\t"},t4[]={"\t\t\t\t"};
            int k=0;
            char g[]={" : break"},t[]={"\tif "};
            char ch[50];
            for(int j=7+app;j<strlen(a[i]);j++)
            {
                if(a[i][j]!=')')
                {
                        ch[k]=a[i][j];
                        k++;
                }
            }
            ch[k]='\0';
            for(int j=0;j<strlen(ch);j++)
            {
                if(ch[j]=='<' && ch[j+1]=='=')
                {
                    ch[j]='>';
                    ch[j+1]=' ';
                    break;
                }
                else if(ch[j]=='>'&& ch[j+1]=='=')
                {
                    ch[j]='<';
                    ch[j+1]=' ';
                    break;
                }
                else if(ch[j]=='<')
                {
                    for(int h=strlen(ch);h>j;h--)
                        ch[h]=ch[h-1];
                    ch[j]='>';
                    ch[j+1]='=';
                    k++;
                    break;
                }
                else if(ch[j]=='>')
                {
                    for(int h=strlen(ch);h>j;h--)
                        ch[h]=ch[h-1];
                    ch[j]='<';
                    ch[j+1]='=';
                    k++;
                    break;
                }
                else if(ch[j]=='='&& ch[j+1]=='=')
                {
                    ch[j]='!';
                    break;
                }
                else if(ch[j]=='!'&& ch[j+1]=='=')
                {
                    ch[j]='=';
                    break;
                }
            }
            ch[k]='\0';
            strcat(ch,g);
            strcat(t,ch);
            if(app==0)
              strcpy(a[i],t);
            else if(app==1)
            {
                strcat(t1,t);
                strcpy(a[i],t1);
            }
            else if(app==2)
            {
                strcat(t2,t);
                strcpy(a[i],t2);
            }
            else if(app==3)
            {
                strcat(t3,t);
                strcpy(a[i],t3);
            }
            else if(app==4)
            {
                strcat(t4,t);
                strcpy(a[i],t4);
            }
            flag=0;
        }
        if(strcmp(a[i],"do")==0)
        {
            strcpy(a[i],"while True:");

        }
        else if(strcmp(a[i],"\tdo")==0)
        {
            strcpy(a[i],"\twhile True:");

        }
        else if(strcmp(a[i],"\t\tdo")==0)
        {
            strcpy(a[i],"\t\twhile True:");

        }
        else if(strcmp(a[i],"\t\t\tdo")==0)
        {
            strcpy(a[i],"\t\t\twhile True:");

        }
        else if(strcmp(a[i],"\t\t\t\tdo")==0)
        {
            strcpy(a[i],"\t\t\t\twhile True:");

        }
    }
}
void variable(char a[200][100],int *num) //handles int i; char name; etc not int i=10;
{
    int n=*num,i;
    for(i=0;i<n;i++)
    {
        if(strncmp(a[i],"int",3)==0 || strncmp(a[i],"char",4)==0 || strncmp(a[i],"float",5)==0 || strncmp(a[i],"double",6)==0 || strncmp(a[i],"\tint",4)==0 || strncmp(a[i],"\tchar",5)==0 || strncmp(a[i],"\tfloat",6)==0 || strncmp(a[i],"\tdouble",7)==0)
        {
            for(int k=i;k<n;k++)
                strcpy(a[k],a[k+1]);
            n--;
            i--;

        }
    }
    *num=n;
}
void fun(char a[200][100],int *num)// handles all function defined before main.
{
    int i,n;
    n=*num;
    for(i=0;i<n;i++)
    {
        int k=0,loc=0;
        char var[100],temp[]={"def"};
        int len=0;
        if(strncmp(a[i],"int",3)==0 || strncmp(a[i],"void",4)==0 || strncmp(a[i],"float",5)==0 || strncmp(a[i],"double",6)==0)
        {
            if(strcmp(a[i],"int main()")==0)
                break;
            if(strncmp(a[i],"int",3)==0)
                len=3;
            else if(strncmp(a[i],"void",4)==0)
                len=4;
            else if(strncmp(a[i],"char",4)==0)
                len=4;
            else if(strncmp(a[i],"float",5)==0)
                len=5;
            else if(strncmp(a[i],"double",6)==0)
                len=6;
            for(int j=len;j<strlen(a[i]);j++)
            {
                if(a[i][j]!=')')
                {
                    var[k]=a[i][j];
                    k++;
                }
                if(a[i][j]==')')
                {
                    var[k++]=a[i][j];
                    break;
                }
            }
            var[k]='\0';
            for(int j=0;j<strlen(var);j++)
            {
                if(var[j]=='(' || var[j]==',')
                {
                    for(int k=j+1;k<strlen(var);k++)
                    {
                        if(var[k]=='i' && var[k+1]=='n' && var[k+2]=='t')
                        {
                            for(int h=0;h<4;h++)
                            {
                                for(int g=k;g<strlen(var);g++)
                                    var[g]=var[g+1];
                            }
                        }
                        if(var[k]=='c' && var[k+1]=='h' && var[k+2]=='a' && var[k+3]=='r')
                        {
                            for(int h=0;h<5;h++)
                            {
                                for(int g=k;g<strlen(var);g++)
                                    var[g]=var[g+1];
                            }
                        }
                        if(var[k]=='f' && var[k+1]=='l' && var[k+2]=='o' && var[k+3]=='a' && var[k+4]=='t')
                        {
                            for(int h=0;h<6;h++)
                            {
                                for(int g=k;g<strlen(var);g++)
                                    var[g]=var[g+1];
                            }
                        }
                        if(var[k]=='d' && var[k+1]=='o' && var[k+2]=='u' && var[k+3]=='b' && var[k+4]=='l' && var[k+5]=='e')
                        {
                            for(int h=0;h<7;h++)
                            {
                                for(int g=k;g<strlen(var);g++)
                                    var[g]=var[g+1];
                            }
                        }
                    }
                }
                loc=j;
            }
            var[loc+1]=':';
            strcat(temp,var);
            strcpy(a[i],temp);
        }
    }
}
void swch(char a[200][100],int *num)//handles switch cases.
{
    int n;
    n=*num;
    for(int i=0;i<n;i++)
    {
        int app=0,loc=0,flag=0,pos=0;
        char var[20];
        char temp2[20];
        if(strncmp(a[i],"switch",6)==0 || strncmp(a[i],"\tswitch",7)==0 || strncmp(a[i],"\t\tswitch",8)==0)
        {
            if(strncmp(a[i],"switch",6)==0)
                app=1;
            else if(strncmp(a[i],"\tswitch",7)==0)
                app=2;
            else if(strncmp(a[i],"\t\tswitch",8)==0)
                app=3;
            for(int j=0;j<strlen(a[i]);j++)
            {
                if(a[i][j]=='(')
                {
                    for(int k=j+1;k<strlen(a[i]);k++)
                    {
                        var[loc]=a[i][k];
                        loc++;
                        if(a[i][k+1]==')')
                            break;
                    }
                    var[loc]='\0';
                    break;
                }
            }
            strcpy(temp2,var);
            int flag3=0;
            for(int j=i;j<n;j++)
            {
                if(strcmp(a[j],"\t{")==0 || strcmp(a[j],"\t}")==0 || strcmp(a[j],"\t\t{")==0 || strcmp(a[j],"\t\t}")==0 || strcmp(a[j],"\tbreak")==0 || strcmp(a[j],"\t\tbreak")==0 || strcmp(a[j],"\t\t\tbreak")==0 || strncmp(a[i],"switch",6)==0 || strncmp(a[i],"\tswitch",7)==0 || strncmp(a[i],"\t\tswitch",8)==0)
                {
                    for(int k=j;k<n;k++)
                    {
                        strcpy(a[k],a[k+1]);
                    }
                    n--;
                    j--;
                }
                else if(strncmp(a[j],"\tdefault",8)==0 || strncmp(a[j],"\t\tdefault",9)==0 || strncmp(a[j],"\t\t\tdefault",10)==0)
                {
                    int jj=j+1;
                    for(int g=0;g<strlen(a[jj]);g++)
                    {
                        a[jj][g]=a[jj][g+1];
                    }
                    jj++;
                    flag3=1;
                    break;
                }
                else
                {
                    if(flag3==1)
                        break;
                    for(int g=0;g<strlen(a[j]);g++)
                    {
                        a[j][g]=a[j][g+1];
                    }
                }

            }
            for(int j=i;j<n;j++)
            {
                strcpy(temp2,var);
                char i1[100]={"if "},i2[100]={"elif "},i3[100]={"else:  "};
                char tab1[100]={"\t"},tab2[100]={"\t\t"},eq[100]={"=="},cl[100]={"        "};
                char temp[20];
                strcpy(temp,cl);
                strcpy(temp,temp2);
                if(strncmp(a[j],"\tcase",5)==0 || strncmp(a[j],"\t\tcase",6)==0)
                {
                    pos++;
                    for(int h=0;h<4+app;h++)
                    {
                        for(int g=0;g<strlen(a[j]);g++)
                            a[j][g]=a[j][g+1];
                    }
                    strcat(eq,a[j]);
                    strcat(temp,eq);
                    if(pos==1)
                    {
                        strcat(i1,temp);
                        if (app==1)
                            strcpy(a[j],i1);
                        else if(app==2)
                        {
                            strcat(tab1,i1);
                            strcpy(a[j],tab1);
                        }
                        else if(app==3)
                        {
                            strcat(tab2,i1);
                            strcpy(a[j],tab2);
                        }
                    }
                    else if(pos>1)
                    {
                        strcat(i2,temp);
                        if (app==1)
                            strcpy(a[j],i2);
                        else if(app==2)
                        {
                            strcat(tab1,i2);
                            strcpy(a[j],tab1);
                        }
                        else if(app==3)
                        {
                            strcat(tab2,i2);
                            strcpy(a[j],tab2);
                        }
                    }
                }
                if(strncmp(a[j],"\tdefault",8)==0 || strncmp(a[j],"\t\tdefault",9)==0)
                {
                    if (app==1)
                            strcpy(a[j],i3);
                    else if(app==2)
                    {
                        strcat(tab1,i3);
                        strcpy(a[j],tab1);
                    }
                    else if(app==3)
                    {
                        strcat(tab2,i3);
                        strcpy(a[j],tab2);
                    }
                    pos=0;
                    break;
                }
            }

        }
    }
    *num=n;
}
void listConvert(char inputString[200][100],int *num)
{
    int s,n=*num;
    for(s=0;s<n;s++)
    {
        int app=0;
        char innerStringOne[200][100] /*variable name*/, innerStringTwo[200][100] /*copy of inputString*/, innerStringThree[200][100], innerStringFour[200][100];
		//condition for application of function
		//--------------------------------------------------------
		int flag1 = 0, flag2 = 0, flag3 = 0;
		if(inputString[s][0]=='i' && inputString[s][1]=='n' && inputString[s][2]=='t')
			flag1 = 1;
        else if(inputString[s][0]=='\t' && inputString[s][1]=='i' && inputString[s][2]=='n' && inputString[s][3]=='t')
        {

            flag1=1;
            app=1;
        }
		for(int i = 0; i<strlen(inputString[s]); i++)
			{
				if(inputString[s][i]=='[')
					flag2 = 1;
				if(inputString[s][i]=='=')
					flag3 = 1;
			}

		strcpy(innerStringTwo[s], inputString[s]);
		//---------------------------------------------------------
		if(flag1==1 && flag2==1 && flag3 == 1)
		{
			//isolating the variable name: assigning to the string innerStringOne.
			//----------------------------------------------------
			for(int i = 4; i<strlen(inputString[s]); i++)
			{
				if(inputString[s][i]=='[')
				{
					inputString[s][i]='\0';
				}
				innerStringOne[s][i-4]=inputString[s][i];
			}
			//-----------------------------------------------------
			//isolating the array: i.e assigning {1,2,3} to the variable innerStringThree.
			//-----------------------------------------------------
			int index1;
			for(int i = 0; i<strlen(innerStringTwo[s]); i++)
			{
				if(innerStringTwo[s][i]=='{')
					index1 = i;
			}
			for(int i = index1; i<strlen(innerStringTwo[s]); i++)///////////
			{
				innerStringThree[s][i-index1] = innerStringTwo[s][i];
			}
			innerStringThree[s][strlen(innerStringThree[s])] = '\0';
			//-----------------------------------------------------
			//concatenation
			//-----------------------------------------------------
			strcat(innerStringOne[s],"=");
			strcat(innerStringOne[s], innerStringThree[s]);
			strcpy(inputString[s], innerStringOne[s]);
			strcpy(innerStringFour[s], innerStringOne[s]);
			for(int i = 0; i<strlen(inputString[s]); i++)
			{
				if(inputString[s][i]=='{')
					inputString[s][i]='[';
				else if(inputString[s][i]=='}')
					inputString[s][i]=']';
			}
			for(int i = 0; i<strlen(inputString[s]); i++)
			{
				if(inputString[s][i]==']')
				{
					inputString[s][i+1]='\0';
				}
			}
			if(app==1)
                    inputString[s][0]='\t';
			//-----------------------------------------------------

		}
    }
}
void printFunction(char inputString[200][100],int *num)
{
    int s,n=*num;
    for(s=0;s<n;s++)
    {
        int app=0,flag=0;
        if(inputString[s][0]=='p' && inputString[s][1]=='r' && inputString[s][2]== 'i' && inputString[s][3]== 'n' && inputString[s][4]=='t')
        {
                 app=0;
                 flag=1;
        }
         else if(strncmp(inputString[s],"\tprintf",7)==0)
        {
               app=1;
               flag=1;
        }
        else if(strncmp(inputString[s],"\t\tprintf",7)==0)
        {
               app=2;
               flag=1;
        }
        else if(strncmp(inputString[s],"\t\t\tprintf",7)==0)
        {
               app=3;
               flag=1;
        }
        if(flag==1)
        {
            //part-1
            //---------------------------------------------------------------------------------------------------------------
            char innerStringOne[200][100], innerStringTwo[200][100];
            char innerStringThree[200][200];
            char innerStringFive[200][200];
            for(int i = 7+app; i <strlen(inputString[s]); i++)
            {
                innerStringOne[s][i-7-app] = inputString[s][i];
            }
            for(int i = 0+app; i<strlen(innerStringOne[s]); i++)
            {
                if(innerStringOne[s][i]==';')
                {
                    innerStringOne[s][i-1]='\0';
                }
            }
            strcpy(inputString[s],innerStringOne[s]);
            //----------------------------------------------------------------------------------------------------------------
            //part-2
            //----------------------------------------------------------------------------------------------------------------
            for(int i = 0+app; i<strlen(inputString[s]); i++)
            {
                if(inputString[s][i]=='%')
                {
                    inputString[s][i]='{';
                    inputString[s][i+1]='}';
                }
            }
            strcpy(innerStringTwo[s],inputString[s]);
            //----------------------------------------------------------------------------------------------------------------
            //part-3
            //---------------------------------------------------------------------------------------------------------------
            for(int i = 1+app; i<strlen(innerStringTwo[s]); i++)
            {
                if(innerStringTwo[s][i]=='"')
                    innerStringTwo[s][i+1] = '\0';
            }
            int count = 0;
            for(int i = strlen(innerStringTwo[s])+1; i<strlen(inputString[s]); i++)
            {
                innerStringThree[s][i-(strlen(innerStringTwo[s])+1)] = inputString[s][i];
                count+=1;
            }
            innerStringThree[s][count] = '\0';
                strcpy(innerStringFive[s],"print(");
            if(app==1)
                strcpy(innerStringFive[s],"\tprint(");
            else if(app==2)
                strcpy(innerStringFive[s],"\t\tprint(");
            else if(app==3)
                strcpy(innerStringFive[s],"\t\t\tprint(");
            strcat(innerStringFive[s], innerStringTwo[s]);
            int count_2 = 0;
            for(int i = 0+app; i<strlen(innerStringTwo[s]); i++)
            {
                if(innerStringTwo[s][i]=='{')
                    count_2+=1;
            }
            if(count_2>0)
            {
                strcat(innerStringFive[s], ".format(");
                strcat(innerStringFive[s], innerStringThree[s]);
                strcat(innerStringFive[s], ")");
            }
            else
                strcat(innerStringFive[s], ")");
            //----------------------------------------------------------------------------------------------------------------
            strcpy(inputString[s], innerStringFive[s]);
        }
    }
}
void logAnd(char inputString[200][100],int *num)
{
    int s,n=*num;
    for(s=0;s<n;s++)
    {
        for(int i = 0; i<strlen(inputString[s]); i++)
        {
            if(inputString[s][i]=='&' && inputString[s][i+1]=='&')
            {
                for(int j = i; j<strlen(inputString[s]); j++)
                {
                    inputString[s][strlen(inputString[s])-(j-i)]=inputString[s][strlen(inputString[s])-(j-i)-1];
                }
                inputString[s][i+1]=' ';
                inputString[s][i]='a';
                inputString[s][i+1]='n';
                inputString[s][i+2]='d';
                //printf("%c \n")
            }
            for(int k=0;k<strlen(inputString[s]);k++)
            {
                if(inputString[s][k]==')')
                {
                    for(int f=k+2;f<strlen(inputString[s]);f++)
                        inputString[s][f]=' ';
                }
                inputString[s][strlen(inputString[s])-1]=='\0';
            }
        }
    }
}
void logOr(char inputString[200][100],int *num)
{
    int s,n=*num;
    for(s=0;s<n;s++)
    {
        for(int i = 0; i<strlen(inputString[s]); i++)
        {
            if(inputString[s][i]=='|' && inputString[s][i+1]=='|')
            {
                inputString[s][i]='o';
                inputString[s][i+1]='r';
            }
        }
        inputString[s][strlen(inputString[s])]='\0';
        //return inputString;
    }
}
void conditionConvert(char inputData[200][100], int *num)
{
    int n=*num;
	for(int i=0;i<n;i++)
	{
		//converting else if to elif
		for(int j = 0; j<strlen(inputData[i]); j++)
		{
			if(inputData[i][j]=='e' && inputData[i][j+1]=='l' && inputData[i][j+2]=='s' && inputData[i][j+3]=='e' && inputData[i][j+4]==' ' && inputData[i][j+5]=='i' && inputData[i][j+6]=='f')
			{
				inputData[i][j+2] = 'i';
				inputData[i][j+3] = 'f';
				int cnt=0;
				while(cnt<=2)
                {
                    for(int g=j+4;g<strlen(inputData[i]);g++)
                        inputData[i][g]=inputData[i][g+1];
                    cnt++;
                }
                for(int g=j+4;g<strlen(inputData[i]);g++)
                {
                    if(inputData[i][g]==')')
                    {
                        inputData[i][g+1]=':';
                        break;
                    }
                }
			}
			else if(inputData[i][j]=='i' && inputData[i][j+1]=='f')
            {
                for(int g=j+2;g<strlen(inputData[i]);g++)
                {
                    if(inputData[i][g]==')')
                    {
                        inputData[i][g+1]=':';
                        inputData[i][g+2]='\0';
                        break;
                    }

                }
            }

		}
		//adding a colon after else
		for(int j = 0; j<strlen(inputData[i]); j++)
		{
			if(inputData[i][j]=='e' && inputData[i][j+1]=='l' && inputData[i][j+2]=='s' && inputData[i][j+3]=='e')
            {
                inputData[i][j+4] = ':';
                inputData[i][j+5] = '\0';
            }
		}
	}
}
void forLoopConvert(char inputData[200][100], int *num)
{
	for(int i = 0; i<*num; i++)
	{
		//removing the curly braces.
		char innerCharOne, innerStringOne[200], innerStringTwo[200], innerStringThree[200] = "for ", innerStringFour[200];
		//applying the condition for the function application.
		int flag = 0, startingPoint = 0,app=0;
		for(int j = 0; j<strlen(inputData[i]); j++)
		{
			if(inputData[i][0] == 'f' && inputData[i][1]=='o' && inputData[i][2]=='r')
			{
				flag = 1;
				startingPoint = j;
				app=0;
			}
			else if(inputData[i][0] == '\t' && inputData[i][1]=='f' && inputData[i][2]=='o' && inputData[i][3]=='r')
			{
				flag = 1;
				startingPoint = j;
				app=1;
			}
			else if(inputData[i][0] == '\t' && inputData[i][1]=='\t' && inputData[i][2]=='f' && inputData[i][3]=='o' && inputData[i][4]=='r')
			{
				flag = 1;
				startingPoint = j;
				app=2;
			}
		}
		if(flag == 1)
		{
			//storing the name of the variable in the character innerCharOne
			innerCharOne = inputData[i][startingPoint+8];
			// storing the lower limit in the string innerStringOne
			int ind1, ind2;
			for(int j = 0+app; j<strlen(inputData[i]); j++)
			{
				if(inputData[i][j] == '=')
				{
					ind1 = j;
				}

				if(inputData[i][j] == ';')
				{
					ind2 = j;
					break;
				}
			}
			for(int j = ind1+1; j<ind2; j++)
			{
				innerStringOne[j-(ind1+1)] = inputData[i][j];
			}
			innerStringOne[ind2-ind1-1]='\0';
			// storing the upper limit in the string innerStringTwo
			int ind3, ind4;
			for(int j = 0; j<strlen(inputData[i]); j++)
			{
				if(inputData[i][j] == '<' && inputData[i][j+1] == '=')
				{
					ind3 = j+1;
				}

				else if(inputData[i][j] == '<' && inputData[i][j+1] != '=')
				{
					ind3 = j;
				}

				if(inputData[i][j] == ';')
				{
					ind4 = j;

				}
			}
			for(int j = ind3+1; j<ind4; j++)
			{
				innerStringTwo[j-(ind3+1)] = inputData[i][j];

			}

			innerStringTwo[ind4-ind3-1]='\0';
			for(int j = 0; j<strlen(inputData[i]); j++)
			{
				if(inputData[i][j] == '<' && inputData[i][j+1] == '=')
				{
					strcat(innerStringTwo, "+1");
				}
			}

			for(int j = 0; j<strlen(inputData[i]); j++)
			{
				if(inputData[i][j]=='(')
				{
					inputData[i][j] = ' ';
					inputData[i][j+2] = '\0';

				}
			}
			char var_name[50] = {innerCharOne, '\0'};
			strcat(inputData[i], var_name);
			strcat(inputData[i], " in range(");
			strcat(inputData[i], innerStringOne);
			strcat(inputData[i], ",");
			strcat(inputData[i], innerStringTwo);
			strcat(inputData[i], "):");

		}
	}
}
int main()
{
    	char a[200][100],str[100],ch;
    	int i=0,flag=0,n=1,j=0;
    	FILE *f1,*f2;
    	f1=fopen("c-program.txt","r");
    	f2=fopen("py-program.txt","w");
    	//Retrieval of data
    	printf("\n\t\tThe C Program Code is \n\n");
        while((ch=fgetc(f1))!=EOF)
        {
            if(ch!='\n')
            {
                a[i][j]=ch;
                printf("%c",a[i][j]);
                j++;
            }
            else
            {
                a[i][j]='\0';
                printf("\n");
                n++;
                i++;
                j=0;
            }
        }
        //Processing of data
        pri(a,&n);
        fun(a,&n);
        header(a,&n);
    	semi(a,n);
    	scan(a,&n);
    	whiledo(a,&n);
    	swch(a,&n);
    	listConvert(a,&n);
    	variable(a,&n);
    	printFunction(a,&n);
        logAnd(a,&n);
        logOr(a,&n);
        conditionConvert(a,&n);
        forLoopConvert(a,&n);
        //Final output - Python program
        printf("\n\t\tThe Python Code is \n\n");
        for(i=0;i<n;i++)
        {

                fprintf(f2,"%s",a[i]);
                fprintf(f2,"%c",'\n');

        }
        for(i=0;i<n;i++)
        {
            puts(a[i]);
        }
        fclose(f1);
        fclose(f2);
        return 0;
}
