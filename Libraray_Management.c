#include <stdio.h>
#include <stdbool.h>
#include<string.h>
// INSTRUCTIONS --->
// # do not write names like (let us c) write (let_us_c).
// # the feature to write (Let Us C) will be updated later-on using fgets and puts;
typedef struct book {
    char book_name[100];
    char author_name[100];
    int book_id;
    int pages;
} nwbk;

typedef struct issuer {
    char name[50];
    int rollnumber;
    nwbk bookname;
} issue;

int main() {
    nwbk arr[1000];
    int number_of_books = 0;
    issue arriss[1000];
    int number_of_issuers = 0;
    main_menu:
    printf("\n.............W E L C O M E  T O  L I B R A R Y  M A N A G E M E N T  S Y S T E M !...........\n\n");
    printf("FOR ENTERING BOOK          -> 1\n");
    printf("FOR ISSUE BOOK             -> 2\n");
    printf("FOR ACCESSING BOOK DETAILS -> 3\n");
    printf("FOR ACCESSING ISSUE DETAILS-> 4\n");
    printf("FOR DELETING EXISTING BOOK -> 5\n");
    printf("FOR DELETING ISSUER        -> 6\n");
    printf("FOR EXITING                -> 7\n\n");
    printf("ENTER YOUR CHOICE  -> ");
    int choice;
    scanf("%d", &choice);

//entry of book programme...

    if (choice == 1) {
        bool exit_to_main = false;
        while (!exit_to_main) {
            if (number_of_books >= 1000) {
                printf("Book storage is full. Cannot add more books.\n");
                goto main_menu;
            }
            printf("\nEnter details for book %d:\n", number_of_books + 1);
            printf("Book Name: ");
            scanf(" %[^\n]s", arr[number_of_books].book_name);
            printf("Author Name: ");
            scanf(" %[^\n]s", arr[number_of_books].author_name);
            printf("Book Id: ");
            scanf("%d", &arr[number_of_books].book_id);
            printf("Number of Pages: ");
            scanf("%d", &arr[number_of_books].pages);
            number_of_books++;
            printf("\nDo you want to return to the main menu? (y/n): ");
            char yes_no;
            scanf(" %c", &yes_no);
            if (yes_no == 'y' || yes_no == 'Y') {
                exit_to_main = true;
                goto main_menu;
            }
        }
    }

    // programme to issue the book to a student

    else if (choice == 2) {
        bool exit_to_main = false;
        while (!exit_to_main) {
            if (number_of_issuers >= 1000) {
                printf("Issuer storage is full. Cannot add more issuers.\n");
                goto main_menu;
            }
            printf("\nEnter details for issuer %d:\n", number_of_issuers + 1);
            printf("Issuer Name: ");
            scanf(" %[^\n]s", arriss[number_of_issuers].name);
            printf("Roll Number: ");
            scanf("%d", &arriss[number_of_issuers].rollnumber);
            printf("Book Id: ");
            scanf("%d", &arriss[number_of_issuers].bookname.book_id);
            number_of_issuers++;
            printf("\nDo you want to return to the main menu? (y/n): ");
            char yes_no;
            scanf(" %c", &yes_no);
            if (yes_no == 'y' || yes_no == 'Y') {
                exit_to_main = true;
                goto main_menu;
            }
        }
    }

    //programme to find a book by id..

    else if (choice == 3) {
    findbook:
    if (number_of_books == 0) {
        printf("\n............. NO BOOK AVAILABLE TO SHOW :( ...............\n");
        goto main_menu;
    }
    printf("ENTER BOOK ID -> ");
    int book_id_find;
    scanf("%d", &book_id_find);
    bool found = false;
    for (int i = 0; i < number_of_books; i++) {
        if (arr[i].book_id==book_id_find) {
            printf("\nBook name -> %s\n", arr[i].book_name);
            printf("Author name -> %s\n", arr[i].author_name);
            printf("Book Id -> %d\n",arr[i].book_id);
            printf("Pages -> %d\n", arr[i].pages);
            found = true;
            break;
        }
    }
    if (!found) {
        printf("BOOK NOT FOUND\n");
    }
    printf("\nDo you want to return to the main menu? (y/n): ");
    char yes_no;
    scanf(" %c", &yes_no);
    if (yes_no == 'y' || yes_no == 'Y') {
        goto main_menu;
    }
    else goto findbook;
}

//programme to  find the issuer student..

else if (choice == 4) {
    findissue:
    if (number_of_issuers == 0) {
        printf("\n............. NO ISSURES AVAILABLE TO SHOW :( ...............\n");
        goto main_menu;
    }
    printf("ENTER  ISSUERS ROLL NUMBER -> ");
    int rollfind;
    scanf(" %d", &rollfind);
    bool found = false;
    for (int i = 0; i < number_of_issuers; i++) {
        if (arriss[i].rollnumber==rollfind) {
            printf("\nIssuer name -> %s\n", arriss[i].name);
            printf("Issuer rollnumber -> %d\n", arriss[i].rollnumber);
            printf("Issued Book Id -> %d\n", arriss[i].bookname.book_id);
            found = true;
            break;
        }
    }
    if (!found) {
        printf("ISSUER NOT FOUND\n");
    }
    printf("\nDo you want to return to the main menu? (y/n): ");
    char yes_no;
    scanf(" %c", &yes_no);
    if (yes_no == 'y' || yes_no == 'Y') {
        goto main_menu;
    }
    else goto findissue;
}

//programme to remove the book..

if(choice==5){
    deletebook:
    if (number_of_books == 0) {
        printf("\n............. NO BOOK AVAILABLE TO REMOVE :( ...............\n");
        goto main_menu;
    }
    printf("ENTER BOOK ID -> ");
    int delete_id;
    scanf("%d", &delete_id);
    bool found = false;
    for (int i = 0; i < number_of_books; i++) {
        if (arr[i].book_id==delete_id) {
            int temp=i;
            for(int j=temp;j<number_of_books-1;j++){
                arr[j]=arr[j+1];
            }
            number_of_books--;
            found = true;
            break;
        }
    }
    if (!found) {
        printf("BOOK NOT FOUND\n");
    }
    else{
        printf("\nBOOK REMOVED SUCCESSFULLY !!........\n");
    }
    printf("\nDo you want to return to the main menu? (y/n): ");
    char yes_no;
    scanf(" %c", &yes_no);
    if (yes_no == 'y' || yes_no == 'Y') {
        goto main_menu;
    }
    else goto deletebook; 
}

//programme to remove the issuing student..

if(choice==6){
    deleteissue:
    if (number_of_issuers == 0) {
        printf("\n............. NO ISSUER AVAILABLE TO REMOVE :( ...............\n");
        goto main_menu;
    }
    printf("ENTER ISSUER ROLLNUMBER -> ");
    int delrollnumber;
    scanf("%d", &delrollnumber);
    bool found = false;
    for (int i = 0; i < number_of_issuers; i++) {
        if (arriss[i].rollnumber==delrollnumber) {
            int temp=i;
            for(int j=temp;j<number_of_issuers-1;j++){
                arr[j]=arr[j+1];
            }
            number_of_issuers--;
            found = true;
            break;
        }
    }
    if (!found) {
        printf("ISSUER NOT FOUND\n");
    }
    else{
        printf("\nISSUER REMOVED SUCCESSFULLY !!........\n");
    }
    printf("\nDo you want to return to the main menu? (y/n): ");
    char yes_no;
    scanf(" %c", &yes_no);
    if (yes_no == 'y' || yes_no == 'Y') {
        goto main_menu;
    }
    else goto deleteissue;
}

// programme to exit the library management system..

    if(choice==7){
        printf("\nGOOD BYE :).....\n");
        printf("Exited successfully!!");
        return 0;
    }
    return 0;
}