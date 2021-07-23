#include<stdio.h>
#include <stdlib.h> 
#include <string.h>
int main()
{
	char ky[50],pt[100],key[50];
	char m[5][5];
	char mat[25];
	char ch='a';
	int i=0,j=0,a=0,b=0,temp1=0;
	int l,temp=0,flag;
	printf("\nEnter key:");
	gets(ky);
	printf("\nEnter plain text:");
	gets(pt);
	
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			m[i][j]=0;
		}
	}
	//Removing space from key
	temp=0;
	while(ky[temp]!='\0')
	{
		if(ky[temp]==' ')
		{
			l=strlen(ky);
			temp1=temp;
			while(ky[temp1]!='\0')
			{
				ky[temp1]=ky[temp1+1];
				temp1++;
			}
			l--;
		}
		temp++;
	}
	//Removing equal elements from key and storing new key in key[]
	temp=0;
	temp1=0;
	while(ky[temp]!='\0')
	{
		flag=0;
		for(a=0;a<=temp;a++)
		{
			if(key[a]==ky[temp])
			{	
				flag=1;
				break;				
			}
		}
		if(flag==0)
		{
			key[temp1]=ky[temp];
			temp1++;
		}
		temp++;
	}
	key[temp1]='\0';
	
	//Making i and j element as equal
	temp=0;
	while(key[temp]!='\0')
	{
		if(key[temp]=='i' || key[temp]=='j')
		{
			for(a=0;a<temp;a++)
			{
				if(key[a]=='i' || key[a]=='j')
				{
					temp1=temp;
					while(key[temp1]!='\0')
					{
						key[temp1]=key[temp1+1];
						temp1++;
					}
					key[temp1-1]='\0';
				}
			}
		}
		temp++;
	}
	//Storing key in matrix
	temp=0;
	a=0;
	b=0;
	while(key[temp]!='\0')
	{
		if(b==5)
		{
			b=0;
			a++;			
		}
		m[a][b]=key[temp];	
		temp++;
		b++;
	}

	//Storing elements in matrix except key elements
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			temp=0;
			flag=0;
			while(key[temp]!='\0')
			{
				if(key[temp]==ch)
				{
					ch++;
					flag=1;
					break;
				}
				if(ch=='i' || ch=='j')
				{
					for(a=0;a<temp;a++)
					{
						if(key[temp]=='i' || key[temp]=='j')
						{
							ch++;
							flag=1;
							break;
						}
					}
				}
				temp++;
			}
			if(flag==0 && m[i][j]==0)
			{
				m[i][j]=ch;
				ch++;
				if(ch=='i')
					ch++;
			}
			if(m[i][j]==0)
				j--;
		}
	}

	//Display matrix
	printf("\n\nMatrix\n");
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("  %c",m[i][j]);
		}
		printf("\n");
	}
					
}
