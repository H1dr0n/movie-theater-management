void welcome()
{   

    gotoxy(10,3);
    printf("Log in as: ");
    gotoxy(10,5);
    printf("1. Admin");
    gotoxy(10,6);
    printf("2. Customer");
    gotoxy(10,7);
    printf("3. Exit Program");

    gotoxy(10,9);
    printf("Enter your choice: ");
    scanf("%d",&choice);
    // fflush(stdin);

    switch(choice)
    {
        case 1: system("cls"); adminlogin1(); break;

        case 2: system("cls"); customer1(); break;

        case 3: system("cls"); EXIT(); break;

        default: 
        {
            system("cls");
            gotoxy(10,4);
            printf("Invalid choice !");
            gotoxy(10,5);
            printf("Please, enter a correct choice");
            Sleep(1000);
            system("cls");
            welcome();
            break;
        }
    }
}

void adminlogin1()
{   
    gotoxy(10,3);//slowmo
    char d[25] = "Admin Login Portal";
    int j;

    gotoxy(10,1);
    for(j=0;j<20;j++)
    {
        Sleep(50);
        printf("*");
    }
    for(j=0;j<19;j++)
    {
        Sleep(50);
        printf("%c",d[j]);
    }
    for(j=0;j<20;j++)
    {
        Sleep(50);
        printf("*");
    }
    adminLogin();
}

void adminLogin()
{
    char name[] = "admin";
    char pass[] = "12345";
    char N[10],P[10];
    int i=0;
    char ch;
    
    gotoxy(10,4);
    printf("Enter admin username: ");
    scanf("%s",N);
    fflush(stdin);
    //printf("\n");

    if(!(strcmp(name,N)))
    {
        gotoxy(10,5);
        printf("Enter admin password: ");
        scanf("%s",P);
        fflush(stdin);

        /*
        //Hides password 
        while(ch!=13)
        {
            ch = getch();
            if(ch!=13 && ch!=8)
            {
                putch("*");
                P[i] = ch;
                i++;
            }
        }
        P[i]='\0';
        */

        if(!(strcmp(pass,P)))
        {
            system("cls");
            admin();
        }
        else {
            system("cls");
            gotoxy(10,1);
            printf("You have entered incorrect password.");
            gotoxy(10,2);
            printf("Enter username and password again.");
            adminLogin();
        }
    }
    else
    {
        system("cls");
        gotoxy(10,1);
        printf("You have entered incorrect username.");
        gotoxy(10,2);
        printf("Enter username and password again.");
        adminLogin();
    }
}

void admin()
{
    gotoxy(20,1);
    printf("You are in ADMIN mode");
    gotoxy(10,3);
    printf("1. Add Movie");
    gotoxy(10,4);
    printf("2. Delete Movie");
    gotoxy(10,5);
    printf("3. Browse Movies");
    gotoxy(10,6);
    printf("4. Logout");

    gotoxy(10,8);
    printf("Enter your choice:");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1: system("cls"); add_movie(); break;

        case 2: system("cls"); deleteMovies(); break;

        case 3:
        {
            system("cls");
            browse_movies(); 
            
            printf("Press enter to admin panel... ");
            getch();
            system("cls");
            admin();

            break;
        }
        case 4: system("cls"); welcome(); break;

        default: system("cls"); admin(); break;
    }
}

void add_movie()
{   
    system("cls");
    fp = fopen("movies.txt","a+");

    if(getMovie()==1)
    {
        fseek(fp,0,SEEK_END);
        fwrite(&a,sizeof(a),1,fp);
        fclose(fp);
        gotoxy(10,10);
        printf("The record is sucessfully saved");
        gotoxy(10,12);
        printf("Save any more? (Y/N):");
        if(getch()=='n')
        {
            system("cls");
            admin();
        }
        else
            system("cls");

        add_movie();
    }
}

int getMovie()
{   
    int t;
    gotoxy(10,3);
    printf("Enter Movie  information below:");
    gotoxy(10,5);
    printf("4 digit Movie unique id: ");
    scanf("%d",&t);

    if(checkid(t)==0)
    {   
        gotoxy(10,7);
        printf("The movie id already exists.");
        gotoxy(10,8);
        printf("Press enter to get back to admin panel...");
        getch();
        system("cls");
        admin();
    }
    a.id=t;
    gotoxy(10,6);
    printf("Enter Movie name: ");
    scanf("%s",a.movName);
    fflush(stdin);
    gotoxy(10,7);
    printf("Enter Movie Date: ");
    scanf("%s",a.date);
    fflush(stdin);
    gotoxy(10,8);
    printf("Enter Movie starting Time: ");
    scanf("%s",a.time);
    fflush(stdin);
    gotoxy(10,9);
    printf("Enter ticket price: ");
    scanf("%d",&a.price);

    return 1;

}

int checkid(int t) //check whether the Movie is exist in theater or not
{   
    //fp = fopen("movies.txt","r+");
    rewind(fp);
    while(fread(&a,sizeof(a),1,fp)==1)
    if(a.id==t)
    {   
        //fclose(fp);
        return 0; //returns 0 if movie exits
    }

    //fclose(fp);
    return 1; //return 1 if it not
}


void deleteMovies() //function that delete items from file fp
{
    system("cls");
    int d;

    system("cls");
    gotoxy(10,3);
    printf("Enter the Movie id to delete: ");
    scanf("%d",&d);

    fp = fopen("movies.txt","r+");
    if(checkid(d)==1)
    {   
        fclose(fp);
        gotoxy(10,5);
        printf("The movie id does not exists.");
        gotoxy(10,6);
        printf("Press enter to get back to admin panel...");
        getch();
        system("cls");
        admin();
    }

    //fp=fopen("movies.txt","r+");
    rewind(fp);
    while(fread(&a,sizeof(a),1,fp)==1)
    {
        if(a.id==d)
        {
            gotoxy(10,5);
            printf("The Movie is available in our theater");
            gotoxy(10,6);
            printf("Movie name is %s\n",a.movName);

            findMovies='t';

        }
            
    }
    if(findMovies!='t')
    {   
        gotoxy(10,8);
        printf("%d movie id is not registered in our movie list",d);
        gotoxy(10,10);
        printf("Press enter to return to admin panel");

        if(getch())
            admin();
    }
    if(findMovies=='t')
    {   
        gotoxy(10,8);
        printf("Do you want to delete it?(Y/N):");
        if(getch()=='y')
        {
            ft=fopen("test.txt","w+");  //temporary file for delete
            rewind(fp);
            while(fread(&a,sizeof(a),1,fp)==1)
            {
                if(a.id!=d)
                {
                    fseek(ft,0,SEEK_CUR);
                    fwrite(&a,sizeof(a),1,ft); //write all in tempory file except that we want to delete
                }
            }
            fclose(fp); fclose(ft);
            
            remove("movies.txt");
            rename("test.txt","movies.txt"); //copy all item from temporary file to fp except that we want to delete
            //fclose(fp); fclose(ft);

            fp=fopen("movies.txt","r+");
            if(findMovies=='t')
            {   
                gotoxy(10,10);
                printf("The movie is successfully deleted.\n");
                fclose(fp);
            }
        }

        else
        {
            system("cls");
            admin();
        }

        fflush(stdin);
    }
    gotoxy(20,12);
    printf("Press enter to go back to admin panel...");
    getch();
    system("cls");
    admin();
}

void browse_movies()
{   
    int i=0,j;
    system("cls");
    gotoxy(1,1);
    printf("*******************MOVIE LIST*******************");
    gotoxy(2,3);
    printf("  ID  MOVIE NAME      DATE      TIME     PRICE ");
    j=5;

    fp = fopen("movies.txt","r");
    rewind(fp);

    while(fread(&a,sizeof(a),1,fp)==1)
    {   
        gotoxy(3,j);
        printf("%d",a.id);
        gotoxy(9,j);
        printf("%s",a.movName);
        gotoxy(24,j);
        printf("%s",a.date);
        gotoxy(33,j);
        printf("%s",a.time);
        gotoxy(42,j);
        printf("%d",a.price);

        printf("\n\n");
        j++;
    }
    fclose(fp);
    gotoxy(1,j+1);
    
}

int EXIT()
{
    system("cls");
    gotoxy(20,3);
    printf("Movie Theater Management");
    gotoxy(22,4);
    printf("Console Application");
    gotoxy(27,5);
    printf("Is Made by");

    /*gotoxy(10,7);
    printf("Anowar Hossain Sunny");
    gotoxy(15,8);
    printf("203-15-3870");
    gotoxy(36,7);
    printf("Rakibul Islam Shanto");
    gotoxy(40,8);
    printf("203-15-3871");
    gotoxy(11,10);
    printf("Faiza Noshin Tithi");
    gotoxy(15,11);
    printf("203-15-3878");
    gotoxy(40,10);
    printf("Jahid Imran");
    gotoxy(40,11);
    printf("203-15-3887"); */

    char ch[40] = "Anowar Hossain Sunny";
    int i;
    gotoxy(10,7);
    for(i=0;i<strlen(ch);i++)
    {
        Sleep(45);
        printf("%c",ch[i]);
    }
    strcpy(ch,"203-15-3870");
    gotoxy(15,8);
    for(i=0;i<strlen(ch);i++)
    {
        Sleep(45);
        printf("%c",ch[i]);
    }
    strcpy(ch,"Rakibul Islam Shanto");
    gotoxy(36,7);
    for(i=0;i<strlen(ch);i++)
    {
        Sleep(45);
        printf("%c",ch[i]);
    }
    strcpy(ch,"203-15-3871");
    gotoxy(40,8);
    for(i=0;i<strlen(ch);i++)
    {
        Sleep(45);
        printf("%c",ch[i]);
    }
    strcpy(ch,"Faiza Noshin Tithi");
    gotoxy(11,10);
    for(i=0;i<strlen(ch);i++)
    {
        Sleep(45);
        printf("%c",ch[i]);
    }
    strcpy(ch,"203-15-3878");
    gotoxy(15,11);
    for(i=0;i<strlen(ch);i++)
    {
        Sleep(45);
        printf("%c",ch[i]);
    }
    strcpy(ch,"Jahid Imran");
    gotoxy(40,10);
    for(i=0;i<strlen(ch);i++)
    {
        Sleep(45);
        printf("%c",ch[i]);
    }
    strcpy(ch,"203-15-3887");
    gotoxy(40,11);
    for(i=0;i<strlen(ch);i++)
    {
        Sleep(45);
        printf("%c",ch[i]);
    }

    
    gotoxy(10,13);
    printf("Thank you for using our console application");
    for(i=4;i>=1;i--)
    {   
        Sleep(1000);
        gotoxy(16,15);
        printf("Exiting in %d second...........>",i);
    }

    return 0;
}


void gotoxy (int x, int y)
{
       coord.X = x; coord.Y = y; // X and Y coordinates
       SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}