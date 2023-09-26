## **CHAPTER – 1**

**INTRODUCTION**

**1.1 PROBLEM STATEMENT**

Create a playlist that is a collection/list of songs. Each song is represented by Song name, Artist and Duration. Basic operations like inserting a song, deleting a song and displaying the playlist need to be included. While displaying the playlist the number of songs and total duration of the playlist should be shown. Along with basic operations, the following features need to be added:

1. Search for a song  
2. Sort the playlist by Song name, Artist and Duration  
3. Reverse the playlist  
4. Shuffle the playlist in random order  
5. Create a music library of different genres and the user should be able to select a particular song and add it to the playlist  
6. Play option to go through the songs  
7. While a song is playing the background color should keep changing  
8. Save option to store the contents of the playlist in a separate file  
9. Open option to retrieve a saved playlist  


**1.2 OBJECTIVES**

Here is the list of actions that need to be accomplished -

1. Choose the appropriate data structure/s to implement the playlist and learn about the chosen data structure's.  
2. Design the overall algorithm/flowchart of the program.  
3. Implement basic functionalities step by step: For insert and delete provide options for the user to choose a specific position to insert/delete the song. For display use a proper format for different headings and show the number of songs and total duration  
4. Implement the extended functionalities mentioned in the problem statement.  
5. Create a music library consisting of various music genres by creating different text files which the user can view and append songs to the playlist.  
6. Implement a play option to go through the songs in the playlist.  
7. Change the background color while a song is playing.  
8. Save the contents of the playlist to a file and retrieve a saved playlist from a file.  
9. Keep testing the program after every step.  


**1.3 METHODOLOGY** 
A menu-driven interface using switch case statements will be followed. Memory will be allocated at run time for the playlist. Based on the user’s choice from the menu the respective function will be executed. For this project, a singly linked list has been used to implement the playlist wherein each node represents a song and its attributes. Arrays are used to store various names like song names and file names. The concept of threads has been used to change the background color simultaneously as a song is playing. File handling concepts were used to search for songs, read, and write to files.

**1.4 EXPECTED OUTCOMES**

1. The user gets to manage his/her songs in a proper playlist.  
2. The playlist can be made offline and retrieved when the application is run again.  
3. User saves time in searching for songs.  
4. User gets to create special melodies by combining specific songs in the playlist.  
5. Get an enhanced experience with a background colour change.  

**1.5 HARDWARE AND SOFTWARE REQUIREMENTS**

**Hardware requirements** -  
A computer  
Dual-core 2Ghz processor recommended for optimal performance  
At least 1GB of Storage  
2GB RAM  

**Software requirements** – 
An IDE to develop C code (like Dev C++)  
Preferably a Windows Operating system  
Text files for Music library.  


## **CHAPTER 2**

**DATA STRUCTURES**

**2.1 LINKED LIST**

The items of a linked list are stored at non-contiguous memory addresses and are arranged in a linear data structure without a defined size.
Each element is represented by a node, which has data and a reference to the node after it. The Head pointer is a reference to the first element. The final node's connection is NULL, indicating that the linked list has ended. In this project, the entire playlist is represented by a singly linked list. Each node of the linked list has three data fields namely the Song name, Artist, duration and pointer to the next song. 

![Linked List Representation](C:\Users\mary6\OneDrive\Pictures\ll-rep)

**Features of a Linked list**: 

- **Cost of Accessing an Element**: In a linked list, direct access is not feasible; instead, we must traverse the current reference to the requested element. The number of nodes affects how easily you can access the items.

**Fig. 2.2: Linked-list accessing**

Here to access 5, we had to traverse temp all the way to 5 and then use the arrow operator (temp->data) to access 5.

Time complexity = O(n)

- **Memory requirement**: More in Linked list as extra memory is needed for pointer variable.

E.g. In Linked list for 7 elements = 7\*8 = 56 bytes

- **Memory Utilization**: More efficient in LL as memory is allocated dynamically. 

- **Cost of insertion**: 

At the beginning – Just update the links of head pointer and new node. Time – O(1)

At i<sup>th</sup> position – Depending on which position we want to insert we traverse the pointer up to the required position. Time – O(n) for worst case

At end - Traverse the LL from beginning to the end to insert element. Only sequential access is possible in Linked list. Time – O(n)

- **Cost of deletion**: Same as cost of insertion
- **Easy to use**: Linked list is more complicated.
- **Searching**: Only linear search is possible

**2.2 ARRAYS**

A linear data structure called an array is a fixed-size data structure in which the elements of same data type are stored at adjacent memory locations. The address of the first element is signified by the array name.





**Fig. 2.3: Array representation**

An array having a fixed size of 6 and a starting index of 0 is logically represented in the image above.

In this project, Arrays have been used to store Song names, artist names and file names.

**Features of Arrays:** 

- **Cost of Accessing an element**: Since arrays allow for random access, elements can be accessed more quickly.

**A[2]** = base address + index value\*size of data type                                                                                                                                                                                            **=**          100 + 2\*4=108** 

**A[2] = 4**     

Time complexity = O(1)** 

- **Memory requirement**: Lesser in Array

Eg: In Array for 7 elements = 28 bytes

- **Memory Utilization**: Inefficient in array as fixed size should be specified in advance. 

- **Cost of insertion**: 

At the beginning - All the elements have to be shifted by one memory address to insert an element. Time complexity – O(n)                                                                                            At i<sup>th</sup> position – Depending on which position we want to insert we shift the elements accordingly.  Time complexity – O(n-p)    ; p-position                                                                At end - We can directly insert at end. Time - O(1)

- **Cost of deletion**: Same as cost of insertion
- **Easy to use**: Array is easier to use.
- **Searching**: Easier in array. Linear and binary search is possible.


















##
## **CHAPTER 3**
**DESIGN**

**3.1 DESIGN GOALS**

Usability: The playlist should have an intuitive user interface and be simple to use.  Scalability: The playlist should be able to handle a large number of songs and make it simple to add and remove them.                                                                                                          Performance: The playlist should perform efficiently and quickly, with a fast search and retrieval time for songs.                                                                                                           Reliability: The playlist should offer a consistent user experience, be robust and stable, with few bugs and mistakes.

**3.2 ALGORITHM/PSEUDO-CODE**

Step-1: Start 

Step-2: Display the menu of options to the user.

Step-3: Read the user's choice.                  

Step-4: Using a switch statement, execute the corresponding function for the selected option.

a. If the user selects "Create," call the create function.                                                              

`             `4a.1 Allocate new memory block for a new node.                                                                                                                   4a.2 Read the song name, artist name, and duration of the song from the user.                        4a.3 Store the song name, artist name, and duration of the song in the new node.              4a.4 Set the link to next node of the new node to 0.                                                                               4a.5 If the linked list is empty (head is equal to 0), set the head and a temporary pointer to the new node.                                                                                                                                     4a.6 If the linked list is not empty, set the last node’s next pointer to the new node and update the temporary pointer to the new node.

b. If the user selects "Display," call the display function.

`             `4b.1 Print the respective headings                                                                                     4b.2 Calculate total number of songs and total duration of playlist.                                                                               4b.3 Print the song name, artist and duration                                                                4b.4 While printing song’s duration, If the song's duration (in minutes) is less than 60, print duration in the format "MM:SS". If the song's duration is more than 60 minutes, calculate the hours and minutes by dividing the duration by 60 and print duration in the format "HH:MM:SS".

c. If the user selects "Insert," call the insert function. 

`             `4c.1 If List is empty, ask user to first create a song.                                                        4c.2 If List is not empty, ask user whether he wants to insert song at beginning, specific position or end.                                                                                                       4c.3 Allocate new memory block for new node.                                                                                                                                          4c.4 Read song name, artist and duration.                                                                      4c.5 Based on user’s choice of position insert the song in the respective position.

d. If the user selects "Delete," call the del function.

`             `4d.1 Similar to insert function, but here you have to free the node to be deleted based on user’s choice.

e. If the user selects "Search," call the search function and display the result.

`             `4e.1 Read the song name                                                                                                       4e.2 Traverse through the playlist and if match is found return position of song               4e.3 If match not found return -1.

f. If the user selects "Sort," call the sort function.

`              `4f.1 Check if the linked list is empty, if yes, then display a message "First create a song".                                                                                                                                           4f.2 If the linked list is not empty, then display the sorting options: sort by song name, sort by artist name, and sort by duration.                                                              4f.3 Read the user's choice for sorting.                                                                                      4f.4 Based on whether the user chooses to sort by song name, artist or duration implement a bubble sort algorithm to sort the linked list by the song name, artist or duration.

g. If the user selects "Reverse," call the reverse function.

`             `4g.1 Check if the head node is NULL. If it is, return a message that the list is empty.   4g.2 Initialize three pointers: prevnode to 0, currnode and nextnode to the head pointer of the list                                                                                                                  4g.3 Enter a while loop, which continues until nextnode is not equal to 0 (end of the list has been reached).                                                                                                            4g.3.1 Within the loop:                                                                                                             4g3.2 Update nextnode pointer to the next node in the list.                                                       4g3.3 Update currnode's next pointer to point to the previous node (prevnode).                    4g3.4 Update prevnode to the current node (currnode).                                                          4g3.5 Update currnode to the next node (nextnode).                                                                                                                           4g.4 After the loop ends, update the head of the list to prevnode, which is the last node in the original list and is now the first node in the reversed list.     

h. If the user selects "Play," call the play function.                                                                        

`             `4h.1 Read the user's choice of starting position for playing the songs.                             4h.2 If the choice is to start from the beginning of the list, set a temporary pointer to the head of the list.

`             `4h.3 If the choice is to start from a specific song, call the search function to get the position of the song.                                                                                                             4h.4 In both cases, create a new thread to run the colorchange function.                  4h.5 Traverse the linked list and print the details of each song, until the end of the list is reached.                                                                                                                             4h.6 In the colorchange function, change the terminal's background color repeatedly using the "system" function.                                                                

i. If the user selects "Shuffle," call the shuffle function.                                                                      

`             `4i.1 Check if the head node is NULL. If it is, return.                                                            4i.2 The splithalf() function is called next, which takes the head node of the list as input and returns the node in the middle of the list                                                          4i.2.1  The splithalf() function first calculates the number of nodes in the list, and then iterates through the list to find the node in the middle.                                    4i.2.3 The next pointer of the node before the middle node is set to NULL, effectively splitting the list into two halves.                                                                      4i.2.4 The middle node is then returned as the result.                                                         4i.3 The makenew() function is called next, which takes two nodes as input and shuffles the elements of the linked list.                                                                               4i.3.1 The function uses two pointers: first and second, to traverse the two halves of the list.                                                                                                                                  4i.3.2 The elements are then rearranged in alternating order by updating the next pointers of the nodes.                                                                                                          4i.4 Finally, the head of the list is updated to the result of splithalf().                                      

j. If the user selects "Display Music Library," call the displib function.             

`             `4j.1 The user is asked to choose a genre of music.                                                              4j.2 The respective file containing the songs is opened and its contents are shown on the output                                                                                                                                          4j.3 The user is asked if he/she wants to append a song from the Music library to the playlist                                                                                                                                     4j.4 If yes, then the user is asked to input line number of song in the Music library      4j.5 The file pointer is set to 0                                                                                              4j.6 Enter a while loop that continues reading the file line by line                            4j.6.1 Check if the reading line number matches with chosen song line number                 4j.6.2 If yes, call the string token function to tokenize the array containing the entire line with “ ” as the delimiter of the string token function                                                                                                                                        4j.6.3 After tokenizing the array, copy the attributes song name, artist and duration to 3 different character arrays.                                                                                            4j.7 A new node is created and the respective attributes are appended to the new node of the playlist.                                                                                                                  4j.8 The user is asked to choose where to insert the new song – beg, specific position or end and the song is appended accordingly to the playlist.

k. If the user selects "Save," call the save function.            

`              `4k.1 Get the name of the file from the user by printing the message "Enter file name (\*.txt): " and reading the input using scanf.                                                                    4k.2 Open the file in write mode by calling fopen function with the filename and the "w" mode.                                                                                                                                   4k.3 If the file cannot be opened, print the message "Couldn't Open File" and exit the program.                                                                                                                          4k.4 Write the header "SONG NAME", "ARTIST", and "DURATION" to the file by using the fprintf function.                                                                                                    4k.5 Traverse the linked list and write the details of each node to the file in the format "song name", "artist", and "duration". The duration is formatted as a string with minutes and seconds.                                                                                                       4k.6 If the data is written successfully to the file, print the message "Play List stored in the file successfully". Else, print "Error While Writing".                                                        4k.7 Close the file using the fclose function.

l. If the user selects "Open," call the open function.                                                             

`             `4l.1 The function open takes a file name as input and opens it in read mode.                     4l.2 If the file is not found, it displays "Cannot open file".                                             4l.3 The file pointer is set to the exact position from which we want to read the file 4l.4 While The file is read line by line and stored in an array buff -                                          4l.4.1 The array which contains an individual line is tokenized to extract song name, artist and duration.                                                                                                                  4l.4.2 The duration is further tokenized to separate the minutes and seconds. These values are then converted to integers using the atoi function and stored in variables min and sec.                                                                                                                               4l.4.3  A new node is created and the song name, artist, minutes, and seconds are stored in it and inserted to the end of the playlist.                                                         4l.5 The file is then closed.                                                         

m. If the user selects "Exit," exit the program.

Step-5: Repeat steps 2 to 4 until the user selects "Exit."                                   






##
## **CHAPTER 4**
**CONCLUSION**

Playlists offer a convenient way to organize and listen to music, allowing users to have all their favourite songs in one place, ready to play at any time. The music playlist has successfully been implemented using the C programming language. Various algorithms, functions and data structures were used to store, manage and play songs in a user-friendly manner. They can also arrange the order of the songs to match their mood or preferences. Playlists can act as a musical diary, helping to recall memories and emotions associated with specific songs. The Music library serves as a source to refer to for new song names. The playlist can be saved offline and revived when the application is run again.  Some of the future enhancements that can be integrated are – when the project is extended to play real MP3 songs, a remix feature can be added to make a new version of a song by combining different songs taking their timestamps and making new melodies. Currently, only one playlist can be created, it can be extended to manage multiple playlists for different categories. 















**   
**


**REFERENCES**

1\.  https://www.geeksforgeeks.org/

2\. <https://www.programiz.com/dsa/linked-list>

3\. <https://www.youtube.com/@nesoacademy>

4\. <https://www.programiz.com/c-programming/c-file-input-output>

5\. <https://stackoverflow.com/>

6\. https://byjus.com/gate/file-handling-in-c/

7\. https://www.youtube.com/@JacobSorber/videos

8\. https://www.ibm.com/docs/en/zos/2.4.0?topic=functions-pthread-create-create-thread

9\. Data Structures through C in depth by authors S.K. Srivastava and Deepali Srivastava
