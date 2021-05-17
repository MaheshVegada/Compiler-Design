#include<stdio.h> 
#include<ctype.h> 
#include<string.h> 
   
char production[10][10]; 
char findfirst[10][100];  
char findfollow[10][100];  
char follow[10], first[10];  
char cn;
int count,n=0,m=0,k; 

void nextfollow(char c, int c1, int c2) 
{  
    if(!(isupper(c)))   
        follow[m++] = c; 
    else
    { 
        int i = 0,j = 1; 
        for(i = 0; i < count; i++) 
        { 
            if(findfirst[i][0] == c)    break; 
        }   
        while(findfirst[i][j] != '!') 
        { 
            if(findfirst[i][j] != '^')  
                follow[m++] = findfirst[i][j];  
            else{ 
                if(production[c1][c2] == '\0')  
                    Follow(production[c1][0]);  
                else  
                    nextfollow(production[c1][c2], c1, c2+1);  
            } 
            j++; 
        } 
    } 
} 
void Follow(char c) 
{        
    if(production[0][0] == c) { 
        follow[m++] = '$'; 
    } 
    for(int i = 0; i < 10; i++) 
    { 
        for(int j = 3;j < 10; j++) 
        { 
            if(production[i][j] == c) 
            { 
                if(production[i][j+1] != '\0')   
                    nextfollow(production[i][j+1], i, j+3);    
                if(production[i][j+1]=='\0' && c!=production[i][0])  
                    Follow(production[i][0]);  
            }  
        } 
    } 
} 
  
void First(char c, int q1, int q2) 
{     
    if(!(isupper(c))) { 
        first[n++] = c; 
    } 
    for(int fst = 0; fst < count; fst++) 
    { 
        if(production[fst][0] == c) 
        { 
            if(production[fst][3] == '^') 
            { 
                if(production[q1][q2] == '\0') 
                    first[n++] = '^'; 
                else if((production[q1][q2] != '\0') && (q1 != 0 || q2 != 0)) 
                    First(production[q1][q2], q1, (q2+1));  
                else    
                    first[n++] = '^'; 
            } 
            else if(!isupper(production[fst][3])) 
                first[n++] = production[fst][3];  
            else  
                First(production[fst][3], fst, 3);  
        } 
    }  
} 

int main() 
{ 
    int jm=0,km=0,i,choice,total; 
    char c,ch; 
    printf("Enter the number of Productions:");
    scanf("%d",&count);
	for(int i = 0; i < count; i++)
		scanf("%s",production[i]); 
    printf("\nGrammar:\n");
	for(int i = 0; i < count; i++)	printf("%s\n",production[i]);   
    char done[count]; 
    int ptr = -1; 
      
    for(k = 0; k < count; k++) 
        for(int h = 0; h < 100; h++) 
            findfirst[k][h] = '!';  
            
    int p1=0,p2,temp; 
    for(k = 0; k < count; k++) 
    { 
        c = production[k][0]; 
        p2 = 0; 
        temp = 0; 
          
        for(int h = 0; h <= ptr; h++) 
            if(c == done[h])	temp = 1; 
                  
        if(temp == 1)  continue; 
               
        First(c, 0, 0); 
        ptr += 1; 
           
        done[ptr] = c; 
        printf("\nFirst(%c) = { ", c); 
        findfirst[p1][p2++] = c; 
 
        for(i = 0 + jm; i < n; i++) { 
            int flag = 0; 
              
            for(int j = 0; j < p2; j++) 
			{    
                if (first[i] == findfirst[p1][j]) 
                { 
                    flag = 1; 
                    break; 
                } 
            } 
            if(flag == 0) 
            { 
                printf("%c ", first[i]); 
                findfirst[p1][p2++] = first[i]; 
            } 
        } 
        printf("}"); 
        jm = n; 
        p1++; 
    } 
    printf("\n\n"); 
    char done1[count]; 
    ptr = -1; 
      
    for(k = 0; k < count; k++) 
        for(int h = 0; h < 100; h++)  
            findfollow[k][h] = '!';   
    p1 = 0; 
    int ln = 0; 
    for(int b = 0; b < count; b++) 
    { 
        cn = production[b][0]; 
        p2 = 0; 
        temp = 0; 
           
        for(int h = 0; h <= ptr; h++) 
            if(cn == done1[h]) 
                temp = 1; 
                  
        if (temp == 1)	continue; 
        ln += 1; 
          
        Follow(cn); 
        ptr += 1; 
           
        done1[ptr] = cn; 
        printf("Follow(%c) = { ", cn); 
        findfollow[p1][p2++] = cn; 
           
        for(i = 0 + km; i < m; i++) { 
            int flag = 0; 
            for(int j = 0; j < p2; j++)  
            { 
                if(follow[i] == findfollow[p1][j]) 
                { 
                    flag = 1; 
                    break; 
                } 
            } 
            if(flag == 0) 
            { 
                printf("%c ", follow[i]); 
                findfollow[p1][p2++] = follow[i]; 
            } 
        } 
        printf("}\n"); 
        km = m; 
        p1++;  
    } 
}
