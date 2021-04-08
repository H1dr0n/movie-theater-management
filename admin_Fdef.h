int choice;
char findMovies;
FILE *fp, *ft, *fs;
struct movies
{
    int id;
    char movName[25];
    char date[10];
    char time[8];
} a;

int getMovie()
{   
    int t;
    printf("\t\t\t\tEnter Movie  information below:\n\n");
    printf("\t\t\t\t4 digit Movie unique id: ");
    scanf("%d",&t);
    if(checkid(t)==0)
    {
        printf("\t\t\t\tThe movie id already exists\n");
        getch();
        admin();
        return 0;
    }
    a.id=t;
    printf("\n\t\t\t\tBook name: ");
    scanf("%s",a.movName);
    printf("\n\t\t\t\tDate: ");
    scanf("%s",a.date);
    printf("\n\t\t\t\tTime:");
    scanf("%s",a.time);

    return 1;

}
void welcome()
{   

    
    printf("\t\t\t\tLog in as:\n");
    printf("\t\t\t\t1. Admin\n");
    printf("\t\t\t\t2. Customer\n");
    printf("\t\t\t\t3. Exit Program\n\n");

    printf("\t\t\t\tEnter your choice: ");
    scanf("%d",&choice);
    // fflush(stdin);

    switch(choice)
    {
        case 1: system("cls"); adminLogin(); break;

        case 2: system("cls"); customer(); break;

        case 3: system("cls"); ex(); break;

        default: system("cls"); printf("\t\t\t\tInvalid choice !\n\t\t\tPlease, enter a correct choice\n\n"); welcome(); break;
    }
}


void adminLogin()
{
    char name[] = "admin";
    char pass[] = "admin123";
    char N[10],P[10];

    printf("\t\t\t\tAdmin Login Portal\n\n");
    printf("\t\t\t\tUsername: ");
    scanf("%s",N);
    //printf("\n");


    if(!(strcmp(name,N)))
    {
        printf("\t\t\t\tPassword: ");
        scanf("%s",P);
        if(!(strcmp(pass,P)))
        {
            system("cls");
            admin();
        }
        else {
            system("cls");
            printf("\t\t\t\tYou have entered incorrect password.\n\t\t\t\tEnter username and password again.\n\n");
            adminLogin();
        }
    }
    else
    {
        system("cls");
        printf("\t\t\t\tYou have entered incorrect username.\n\t\t\t\tEnter username and password again.\n\n");
        adminLogin();
    }
}

void admin()
{

    printf("\t\t\t\tYou are in ADMIN mode\n\n");
    printf("\t\t\t\t1. Add Movie\n");
    printf("\t\t\t\t2. Delete Movie\n");
    printf("\t\t\t\t3. Browse Movies\n");
    printf("\t\t\t\t4. Logout\n");

    printf("\n\t\t\t\tEnter your choice:");
    scanf("%d",&choice); fflush(stdin);

    switch(choice)
    {
        case 1: system("cls"); add_movie(); break;

        case 2: system("cls"); deleteMovies(); break;

        case 3: system("cls"); browse_movies(); break;

        case 4: system("cls"); welcome(); break;

        default: system("cls"); admin(); break;
    }

}

void add_movie()
{   
    fp = fopen("movies.dat","ab+");

    if(getMovie()==1)
    {
        fseek(fp,0,SEEK_END);
        fwrite(&a,sizeof(a),1,fp);
        fclose(fp);
        printf("\t\t\t\tThe record is sucessfully saved");
        printf("\t\t\t\tSave any more? (Y/N):");
        if(getch()=='n')
            admin();
        else
            system("cls");

        add_movie();
    }
}


void browse_movies()
{
    fp = fopen("movies.dat","rb");

    while(fread(&a,sizeof(a),1,fp)==1)
    {
        printf("%d ",a.id);
        printf("%s ",a.movName);
        printf("%s ",a.date);
        printf("%s ",a.time);

        printf("\n");

    }
    fclose(fp);

    printf("\n\n\t\t\t\tEnter any key to return to admin mode... ");
    getch();
    system("cls");
    admin();
}

void deleteMovies() //function that delete items from file fp
{
    system("cls");
    int d;
    char another='y';
    while(another=='y') //infinite loop
    {
        system("cls");
        
        printf("\t\t\t\tEnter the book id delete: ");
        scanf("%d",&d);

        fp=fopen("movies.dat","rb+");
        rewind(fp);
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(a.id==d)
            {
                printf("\t\t\t\tThe book record is available.\n");
                printf("Movie name is %s\n",a.movName);

                findMovies='t';

            }
            
        }
        if(findMovies!='t')
        {
            printf("\t\t\t\tNo record available.\n");
            if(getch())
                admin();
        }
        if(findMovies=='t')
        {
            printf("\t\t\t\tDo you want to delete it?(Y/N):");
            if(getch()=='y')
            {
                ft=fopen("test.dat","wb+");  //temporary file for delete
                rewind(fp);
                while(fread(&a,sizeof(a),1,fp)==1)
                {
                    if(a.id!=d)
                    {
                        fseek(ft,0,SEEK_CUR);
                        fwrite(&a,sizeof(a),1,ft); //write all in tempory file except that we want to delete
                    }
                }
                fclose(ft);
                fclose(fp);
                remove("movies.dat");
                rename("test.dat","movies.dat"); //copy all item from temporary file to fp except that we want to delete

                fp=fopen("movies.dat","rb+");
                if(findMovies=='t')
                {
                    printf("\t\t\t\tThe record successfully.\n");
                    printf("Delete another record? (Y/N)");
                }
            }
            else admin();

            fflush(stdin);
            another=getch();
        }
    }

    admin();
}

int checkid(int t) //check whether the Movie is exist in theater or not
{
    rewind(fp);
    while(fread(&a,sizeof(a),1,fp)==1)
    if(a.id==t) return 0; //returns 0 if movie exits

    return 1; //return 1 if it not
}

int ex()
{
    return 0;
}