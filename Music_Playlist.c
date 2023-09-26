#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <pthread.h>
#include <stdbool.h>

struct node {
	char songname[50];
	int minutes;
	int seconds;
	char artist[50];
	struct node* next;
};

typedef struct node node;
node* head = 0, * temp = 0, * newnode = 0,*prevnode=0,*nextnode=0,*p=0,*q=0,*r,*s,*tmp,*currnode;

void create() {
	struct node * newnode = (node*)malloc(sizeof(node));
	printf("\nEnter song name: ");
	//gets(song);
	scanf("%s", &newnode->songname);
	printf("\nEnter artist name: ");
	scanf("%s",&newnode->artist);
	do{
	printf("\nEnter the duration of the song (MM:SS) : ");
	scanf("%d:%d",&newnode->minutes,&newnode->seconds);
    }while(newnode->seconds<0 || newnode->seconds>60);
	newnode->next = 0;
	if (head == 0) {
		head = newnode;
		temp = newnode;
	}
	else {
		temp->next = newnode;
		temp = newnode;
	}
}

void getlength(){
	int count=0;
	temp=head;
	if(head==NULL){
		printf("\nPlaylist is empty");
	}else{
	while(temp!=0){
		count++;
		temp=temp->next;
	}
	if(count==1){
    printf("\n1 song");
    }
    else{
    printf("\n%-1d songs",count);
	}
}
}

void getduration(){
	float totaltime, hours, totalseconds;
    int m=0,s=0,totalmin,sec, totalsec, totalhours,min,minute;
	int totaldurationh=0, totaldurationm=0,totaldurations=0;
	temp=head;
	
	if(head==NULL){
	  printf("%60s\n","0 min 0sec\n");	
	}else{
    while(temp!=0){
    	m+=temp->minutes;
    	s+=temp->seconds;
    	temp=temp->next;
	}
	
    sec = (m*60) + s;
    totaltime =(float)sec/60;
    totalmin = (int)totaltime;
    
     if(totalmin<60){
     totalseconds = (totaltime-totalmin)*60;
     if((totalseconds-(int)totalseconds) < 0.5)
     totalsec = floor(totalseconds);
     else
     totalsec = ceil(totalseconds);
     printf("%60d min %d sec\n",totalmin, totalsec);
	 }
	 else
	 {	
    	hours = (float)totalmin/60;
    	totalhours = (int)hours;
    	min = (hours-totalhours)*60;
    	if((min - (int)min)<0.5)
    	minute = floor(min);
    	else
    	minute = ceil(min);
    	printf("%60d hr %d min\n",totalhours, minute);
	}
}
}

void display() {
	int i;
	float h,m;
	int hours,min;
	for(i=0;i<78;i++)
	printf("%s","=");
	printf("\n\nYOUR PLAYLIST\n");
	getlength();
	getduration();
	for(i=0;i<78;i++)
	printf("%s","=");
	printf("\n%-30s %-30s %13s\n","SONG NAME","ARTIST","DURATION");
	for(i=0;i<78;i++)
	printf("%s","-");
	printf("\n");	
	temp=head;
	while (temp != 0) {
		//len=strlen(temp->songname);
		if(temp->minutes<60){
		printf("%-30s %-30s %4s %2c %02d:%02d", temp->songname, temp->artist, "|",' ',temp->minutes,temp->seconds);
	    }else{
	    if(temp->minutes>=60){
		h=(float)(temp->minutes)/60;
	    hours=(int)h;
	    m=(h-hours)*60;
        }
        
        if((m-(int)m)<0.5)
    	min=floor(m);
	    else
		min=ceil(m);
	
	    printf("%-30s %-30s %4s %02d:%02d:%02d", temp->songname, temp->artist, "|",hours, min ,temp->seconds);
		}
		temp = temp->next;
		printf("\n");
	}
}

void insert() {
	int choice, i = 1, pos;
	if(head==NULL){
		printf("\nFirst create a song ");
	}else{
	printf("\n1.Insert at beg\n2.Insert at end\n3.Insert at a particular position\n");
	scanf("%d", &choice);
	newnode = (node*)malloc(sizeof(node));
	printf("\nEnter songname\n");
    scanf("%s", newnode->songname);
    printf("\nEnter artist name: ");
	scanf("%s",&newnode->artist);
    do{
    printf("\nEnter the duration of the song (MM:SS): ");
	scanf("%d:%d",&newnode->minutes,&newnode->seconds);
	}while(newnode->seconds<0 || newnode->seconds>60);
	switch (choice) {
	case 1:
		newnode->next = head;
		head = newnode;
		break;
	case 2:
		newnode->next = 0;
		temp = head;
		while (temp->next != 0) {
			temp = temp->next;
		}
		temp->next = newnode;
		break;
	case 3:
		printf("\nEnter position at which element is to be inserted:\n");
		scanf("%d", &pos);
		temp = head;
		while (i < pos-1) {
			temp = temp->next;
			i++;
		}
		newnode->next = temp->next;
		temp->next = newnode;
		break;
	default:
		printf("\nEnter Valid option\n");
		break;
	}
    }
}

void del() {
	int pos=1,i=1,choice;
	if(head==NULL){
		printf("\nFirst create a song ");
	}else{
	printf("\n1.Delete from beg\n2.Delete from end\n3.Delete from specific position\n");
	scanf("%d",&choice);
	switch (choice) {
	case 1:
		if (head != 0) {
			temp = head;
			head = head->next;
			free(temp);
		}
		else {
			printf("\nList is empty");
		}
		break;
	case 2:
		temp = head;
		if(head!=0){
		while (temp->next != 0) {
			prevnode = temp;
			temp = temp->next;
		}
		if (head->next == 0) {
			head = 0;
		}
		else {
			prevnode->next = 0;
		}
		free(temp);
		}
		break;
	case 3:
		temp = head;
		printf("\nEnter the position:\n");
		scanf("%d",&pos);
		while (i < pos - 1) {
			temp = temp->next;
			i++;
		}
		nextnode = temp->next;
		temp->next = nextnode->next;
		free(nextnode);
		break;
	default:
		printf("\nInvalid choice\n");
	}
}
}


int search()
{
	char song[50];
	int pos=1;
	printf("Enter song name\n");
	scanf("%s", song);
	temp = head;
	while (temp != NULL)
	{
		if (strcmp(temp->songname, song) != 0) {
			temp = temp->next;
			pos++;
		}
		else
		{
			return pos;
		}
	}
	return -1;
}

void reverse(){
	if(head==NULL){
		printf("\nList is empty\n");
	}
	prevnode=0;
	currnode=nextnode=head;
	while(nextnode!=0){
		nextnode = nextnode->next;
		currnode->next = prevnode;
		prevnode = currnode;
		currnode = nextnode;
	}
	head=prevnode;
}

void sort(){
	int choice;
	if(head==NULL){
		printf("\nFirst create a song ");
	}else{
	printf("\n1. Sort by Song name ");
	printf("\n2. Sort by Artist name");
	printf("\n3. Sort by Duration\n");
	choice =scanf("%d",&choice);
	if(choice == 1){
	for(r=p=head; p->next!=NULL; r=p,p=p->next){
		for(s=q=p->next; q!=NULL; s=q,q=q->next){
			if(strcmp(p->songname,q->songname)>0){
				tmp=p->next;
				p->next=q->next;
				q->next=tmp;
				if(p!=head)
				r->next=q;
				s->next=p;
				if(p==head)
				head=q;
				tmp=p;
				p=q;
				q=tmp;
			}
		}
	}
    }else if(choice == 2){
    for(r=p=head; p->next!=NULL; r=p,p=p->next){
		for(s=q=p->next; q!=NULL; s=q,q=q->next){
			if(strcmp(p->artist,q->artist)>0){
				tmp=p->next;
				p->next=q->next;
				q->next=tmp;
				if(p!=head)
				r->next=q;
				s->next=p;
				if(p==head)
				head=q;
				tmp=p;
				p=q;
				q=tmp;
			}
		}
	}	
	}else if(choice == 3){
	 for(r=p=head; p->next!=NULL; r=p,p=p->next){
		for(s=q=p->next; q!=NULL; s=q,q=q->next){
			if(p->minutes > q->minutes){
				tmp=p->next;
				p->next=q->next;
				q->next=tmp;
				if(p!=head)
				r->next=q;
				s->next=p;
				if(p==head)
				head=q;
				tmp=p;
				p=q;
				q=tmp;
			}
		}
	}
}
}
}

void displib(){
   int choice,ch,i=0;
   FILE *fp;
   char buffer[400];
   printf("\nChoose Genre: ");
   printf("\n1. Classical ");
   printf("\n2. Rock");
   printf("\n3. Country");
   printf("\n4. Jazz");
   printf("\n5. Devotional\n");
   scanf("%d",&choice);
   if(fp==NULL){
		printf("Error\n");
	}
   printf("\n");
   if(choice == 1){
   fp = fopen("LibClassical.txt","r");
   while(fgets(buffer,400,fp)){
   printf("%s",buffer);
   }
   }else if(choice == 2){
   fp = fopen("LibRock.txt","r");
   while(fgets(buffer,400,fp)){
   printf("%s",buffer);
   }
   }
   else if(choice == 3){
   	fp = fopen("LibCountry.txt","r");
   while(fgets(buffer,400,fp)){
   printf("%s",buffer);
   }}
   else if(choice == 4){
   	fp = fopen("LibJazz.txt","r");
   while(fgets(buffer,400,fp)){
   printf("%s",buffer);
   }}else{
   	fp = fopen("LibDevo.txt","r");
   while(fgets(buffer,400,fp)){
   printf("%s",buffer);
   }}
   
   printf("\nDo you want to append a song? (1 for yes, 0 for no): ");
   scanf("%d",&ch);
   
   
   if(ch==1) {
   	
   char song[50]={};
   char artist[50]={};
   char duration[10]={};
   int min,sec;
   char buff[60];
   int readline=0;

   printf("Select line number of song: ");
   scanf("%d",&readline);
   fseek(fp,0,SEEK_SET);
   
   while(fgets(buff,sizeof(buff),fp)){
    		i++;
    		if(i==(readline+1)){
    			const char s[2] = " ";
                char *token;
                char num[2];
       
                token = strtok(buff, s);
   
                if(token!=NULL)
                   strcat(num,token);
                   token=strtok(NULL," ");
                   strcat(song,token);
                   token=strtok(NULL," ");
                   strcat(artist,token);
                   token=strtok(NULL," ");
                   strcat(duration,token);
			}
	}
   
   newnode = (node*)malloc(sizeof(node));
   strcpy(newnode->songname, song);
   strcpy(newnode->artist, artist);
   
   char m[3]={};
   char s[3]={};

   char *token2;

   token2 = strtok(duration,":");
   if(token2!=NULL)
   strcat(m,token2);
   token2 = strtok(NULL,"\0");
   strcat(s,token2);

   min = atoi(m);
   sec = atoi(s);
   
   newnode->minutes = min;
   newnode->seconds = sec; 
   
   newnode->next = 0;
    
	if (head == 0) {
		head = newnode;
		temp = newnode;
	}
    else {
     int choi,pos;
     printf("\n1.Insert at beg\n2.Insert at end\n3.Insert at a particular position\n");
     scanf("%d", &choi);
     switch (choi) {
	    case 1:
		    newnode->next = head;
		    head = newnode;
		    break;
	    case 2:
		    newnode->next = 0;
		    temp = head;
		    while (temp->next != 0) {
			   temp = temp->next;
		   }
		   temp->next = newnode;
		   break;
	    case 3:
		   printf("\nEnter position at which element is to be inserted:\n");
		   scanf("%d", &pos);
		   temp = head;
		   while (i < pos - 1) {
		    	temp = temp->next;
			    i++;
		    }
		    newnode->next = temp->next;
		    temp->next = newnode;
		    break;
	    default:
		   printf("\nEnter Valid option\n");
		   break;
	}
}
}
   fclose(fp);
}
  

void *colorchange(){
	int i;	
	for(i=0;i<2;i++){
	system("COLOR 90");
	sleep(1);
	system("COLOR A0");
	sleep(1);
	system("COLOR B0");
	sleep(1);
	system("COLOR C0");
	sleep(1);
	system("COLOR D0");
	sleep(1);
	system("COLOR E0");
	sleep(1);
	system("COLOR F0");
	sleep(1);
    }
system("COLOR 07");
}

void play(){
	int choice,pos,i=1;
	char arr[50];
	pthread_t thread1;
	if(head==NULL){
		printf("\nList is empty\n");
	}
	printf("\n1. From start ");
	printf("\n2. Choose from which song ");
	scanf("%d",&choice);
	if(choice == 1){
	temp = head;
	pthread_create(&thread1,NULL,colorchange,NULL);
	while(temp!=NULL){
		printf("\nNow Playing: %-25s %-20s %4s %2c %02d:%02d", temp->songname, temp->artist, "|",' ',temp->minutes,temp->seconds);
		getch();
		temp=temp->next;
	}
   }
   else{
    pos = search();
    while(i<pos-1){
    	temp=temp->next;
    	i++;
	}
	pthread_create(&thread1,NULL,colorchange,NULL);
	while(temp!=NULL){
		printf("\nNow Playing: %-25s %-20s %4s %2c %02d:%02d", temp->songname, temp->artist, "|",' ',temp->minutes,temp->seconds);
		getch();
		temp=temp->next;
	}
   }
}

node* splithalf(node* start) {
int num = 0,i;
node* cur = start;
for (cur = start; cur != NULL; cur = cur->next) {
num++;
}

for (i = 0; i < num / 2 - 1; i++) {
start = start->next;
}

node* result = start->next;
start->next = NULL;
return result;
}

void makenew(node* first, node* second) {
node* last = NULL;
while (second != NULL) {

if (last == NULL) {
last = second;
} else {
last->next = second;
}

node* next = second->next;
second->next = first;
second = next;
last = first;

next = first->next;
first->next = NULL;
first = next;
}
}

void shuffle(node** head){
	if (* head == NULL) 
	return;
    node* half = splithalf(*head);
    makenew(*head, half);
    *head = half;
}

void save(){
	char filename[30]={};
	temp = head;
    printf("Enter file name (*.txt): ");
    scanf("%s",&filename);
    FILE* file;
    file = fopen (filename, "w");
    if (file == NULL)
    {
        printf("\nCouldn't Open File\n");
        exit (1);
    }
    
    fprintf(file, "%-30s %-30s %13s\n","SONG NAME","ARTIST","DURATION\n");
    while(temp!=NULL)
    {
        fprintf(file, "%-30s %-30s %4c %02d:%02d\n", temp->songname, temp->artist,' ',temp->minutes,temp->seconds);
        temp = temp->next;
    }
    
    if(fprintf > 0)
        printf("Play List stored in the file successfully\n");
    else
        printf("Error While Writing\n");
	    
    fclose(file);
}

void open() {  
	
	char file[20]={};
	char buff[200]={};
    FILE *fp;
    
	printf("\nEnter filename: ");
	scanf("%s", &file);
	fp = fopen(file,"r");
	if(fp == NULL){
		printf("\nCannot open file\n");
	}
	
	fseek(fp,78,SEEK_CUR);
	
	while(fgets(buff,sizeof(buff),fp)){
    char song[50]={};
    char artist[50]={};
    char duration[10]={};
    int min,sec,i=1;
    char m[3]={};
    char s[3]={};
    char *token;

    token = strtok(buff, " ");
   
        if(token!=NULL)
            strcat(song,token);
            token=strtok(NULL," ");
            strcat(artist,token);
            token=strtok(NULL," ");
            strcat(duration,token);
        

   char *token2;

   token2 = strtok(duration,":");
   if(token2!=NULL)
   strcat(m,token2);
   token2 = strtok(NULL,"\0");
   strcat(s,token2);

   min = atoi(m);
   sec = atoi(s);
   
   newnode = (node*)malloc(sizeof(node));
   strcpy(newnode->songname, song);
   strcpy(newnode->artist, artist);
  
   newnode->minutes = min;
   newnode->seconds = sec; 
  
   if (head == 0) {
		head = newnode;
		temp = newnode;
		newnode->next = 0;
    }
	else {
        newnode->next = 0;
		temp = head;
		while (temp->next != 0) {
			temp = temp->next;
		}
		temp->next = newnode;
	}
 } 
fclose(fp);
}
 
int main() {

	int choice,pos;

	while (1) {
		printf("\n***************MAIN MENU***************\n");
		printf("\n1.  Create");
		printf("\n2.  Display");
		printf("\n3.  Insert");
		printf("\n4.  Delete");
		printf("\n5.  Search");
		printf("\n6.  Sort");
		printf("\n7.  Reverse"); 
		printf("\n8.  Play");
		printf("\n9.  Shuffle");
		printf("\n10. Display Music Library");
		printf("\n11. Save");
		printf("\n12. Open");
		printf("\n13. Exit\n");
		scanf("\n%d", &choice);
		switch (choice) {
		case 1:
			create();
			break;
		case 2:
			display();
			break;
		case 3:
			insert();
			break;
		case 4:
			del();
			break;	
		case 5:
			pos = search();
			if(pos!=-1){
			printf("\nSong found at position %d",pos);
		    }
		    else{
				printf("\nSong not found\n");
		    }
		    break;
		case 6:
			sort();
			break;
		case 7:
			reverse(); 
			break;
		case 8:
			play();
			break;	
		case 9:
			shuffle(&head);
			break;
		case 10:
			displib();
			break;
		case 11:
		    save();	
			break;
		case 12:
			open();
			break;
		case 13:
			exit(0);
		default:
			printf("\nEnter valid option: ");
			break;
		}
	}
    return 0;
}

