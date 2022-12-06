#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
 
typedef struct etudiant etudiant;
struct etudiant
{
  int ide;
  char prenom[30];
  char nom[25];
  char classe[25];
};
struct etudiant etd;
typedef struct Date
{
   int jour;
   int mois;
   int annee;
}Date;
typedef struct paiement paiement;
struct paiement
{
  int idp;
  double montant; 
  Date datepaie;
  char objet[20];
  int ide; 
};
struct paiement payer;
int rechide(int ider)
{
   FILE* etud;
   etud=fopen("etudiant.txt","r");
   do
   {
    fscanf(etud,"%d , %s , %s , %s\n",&etd.ide,&etd.prenom,&etd.nom,&etd.classe);
    if(etd.ide==ider)
    {
    fclose(etud);
    return 1;
    }
   }while(!feof(etud));
   fclose(etud);
   return -1;
}
//Mettre en Majuscule tout les Noms
void NomMajuscule(char NoM[25])
{
    int i;
    for(i=0;i<25;i++)
     NoM[i]=toupper(NoM[i]);
}
//Mettre toutes les Classe en Majuscule.
void ClasseMajuscule(char Class[25])
{
    int i;
    for(i=0;i<25;i++)
     Class[i]=toupper(Class[i]);
}
//Avec cette fonction l'etudiant renseigne ses Informations.
void info_Etudiant(etudiant *e)
{
  FILE *etud;
  int id;
  etud=fopen("etudiant.txt","a");
  if(etud == NULL)
  {

    printf("Erreur d'ouverture du fichier \n");
    exit(EXIT_FAILURE);
  }
  printf("ID : ");
  scanf("%d",&id);
  while(rechide(id)==1)
  {
    printf("Cette IDE est deja attribuer\n");
    printf("Veuiller Ressayer une autre\n");
    printf("IDE : ");
    scanf("%d",&id);
  }
  (*e).ide=id;
  printf("Prenom : ");
  scanf("%s",(*e).prenom);
  printf("NOM : ");
  scanf("%s",(*e).nom);
  NomMajuscule(&e->nom);
  printf("Classe: ");
  scanf("%s",(*e).classe);
  ClasseMajuscule(&e->classe);
  fprintf(etud, "%d , %s , %s , %s\n",(*e).ide,(*e).prenom,(*e).nom,(*e).classe);
  fclose(etud);
}
//Cette fonction demande le nombre d'etudiants a Enregistrer en itulisant la fonction info_Etudiant.
void saisie_Etudiant(etudiant a)
{
   int n,i;
   printf("Donner le Nombre d'etudiant a Ajouter : ");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
    info_Etudiant(&a);
   }
}
//afficher la liste des Etudiants qui sont dans la fichiers etudiant.txt
void afficher_Etudiant(etudiant e)
{
  FILE* etud;
  etud=fopen("etudiant.txt","r");

  if(etud==NULL)
  {
    printf("Erreur d'ouverture du fichier \n");
    exit(EXIT_FAILURE);
  }
  printf("\nVoici la Liste des Etudiants\n\n");
  do
  {
   fscanf(etud,"%d , %s , %s , %s\n",&e.ide,&e.prenom,&e.nom,&e.classe);
   printf("%d ,",e.ide);
   printf(" %s ",e.prenom);
   printf(", %s ",e.nom);
   printf(", %s\n",e.classe);
  }while(!feof(etud));
  fclose(etud);
}
//afficher les etudiants par classe en donnant la classe souhaiter.
void etudiant_par_classe(etudiant p)
{
  char Rclasse[25];
  int trouve=0;
  FILE* etud;
  etud=fopen("etudiant.txt","r");
  if(etud==NULL)
  {
    
    printf("Erreur d'ouverture du fichier \n");
    exit(EXIT_FAILURE);
  }
  printf("Donner le nom de la Classe\n");
  scanf("%s",Rclasse);
  ClasseMajuscule(Rclasse);
  printf("\nVoici la liste de la classe : %s\n",Rclasse);
  do
  {
   fscanf(etud,"%d , %s , %s , %s\n",&p.ide,&p.prenom,&p.nom,&p.classe);
   if(strcmp(p.classe,Rclasse)==0)
   {
    printf("%d ,",p.ide);
    printf(" %s",p.prenom);
    printf(" %s ,",p.nom);
    printf(" %s\n",p.classe);
    trouve=trouve+1;
   } 
  }while(!feof(etud));
  fclose(etud);
   if(trouve==0)
   {
    printf("\nCette Classe : %s n'existe pas dans la liste des Classes\n",Rclasse);
   }
}
//Recherche id a partir du fichier etudiant.txt
void rechercher_IDE(etudiant e)
{
  int IDER,trouve=0;
  FILE* etud;
  etud=fopen("etudiant.txt","r");
  if(etud==NULL)
  {

    printf("Erreur d'ouverture du fichier n");
    exit(EXIT_FAILURE);
  }
  printf("\nDonner l'IDE a Chercher : ");
  scanf("%d",&IDER);
  do
  {
    fscanf(etud,"%d , %s , %s , %s\n",&e.ide,&e.prenom,&e.nom,&e.classe);
    if(e.ide==IDER)
    {
      printf("Etudiant Trouve\n");
      printf("%d ,",e.ide);
      printf(" %s\t ",e.prenom);
      printf(", %s\t ",e.nom);
      printf(", %s\n",e.classe);
      trouve=trouve+1;
    }
  }while(!feof(etud));
  fclose(etud);
  if(trouve==0)
  {
      printf("\nCette IDE:%d n'existe pas dans la liste des Etudiants\n",IDER);
  }
}
//rechercher nom a partir du fichier etudiant.txt
void rechercher_NOM(etudiant e)
{
  char NOM[25];
  int trouve=0;
  FILE* etud;
  etud=fopen("etudiant.txt","r");
  if(etud==NULL)
  {

    printf("Erreur d'ouverture du fichier \n");
    exit(EXIT_FAILURE);
  }
  printf("\nDonner le NOM a Chercher : ");
  scanf("%s",NOM);
  NomMajuscule(NOM);
  do
  {
    fscanf(etud,"%d , %s , %s , %s\n",&e.ide,&e.prenom,&e.nom,&e.classe);
    if(strcmp(e.nom,NOM)==0)
    {
      printf("Etudiant Trouve\n");
      printf("%d ,",e.ide);
      printf(" %s\t ,",e.prenom);
      printf(" %s\t ,",e.nom);
      printf(" %s\n",e.classe);
      trouve=trouve+1;
    }
  }while(!feof(etud));
  fclose(etud);
  if(trouve==0)
    {
      printf("\nCette NOM:%s n'existe pas dans la liste des Paiements\n",NOM);
    }
}
//Recherche IDP
int rechidp(int idep)
{
   FILE* paie;
   paie=fopen("paiement.txt","r");
   do
   {
    fscanf(paie, "%d , %lf , %d/%d/%d , %s , %d\n",&payer.idp,&payer.montant,&payer.datepaie.jour,&payer.datepaie.mois,&payer.datepaie.annee,&payer.objet,&payer.ide);
    if(payer.idp==idep)
    {
    fclose(paie);
    return 1;
    }
   }while(!feof(paie));
   fclose(paie);
   return -1;
}

//Saisie du Date de Paiement
void saisie_Date(Date *d)
{    
      do
      {
       printf("Donner le Jour du paiement : ");
       scanf("%d",&(*d).jour);
      }while((*d).jour==0 || (*d).jour>31);
     //le jour ne doit pas t'egal a 0 et ne depasse pas 31.
      do
      {
       printf("Donner le Mois du paiement : ");
       scanf("%d",&(*d).mois);
      }while((*d).mois==0 || (*d).mois>12);
     //le mois ne doit pas t'egal a 0 et ne depasse pas 12.
      do
      {
       printf("Donner l'annee du paiement : ");
       scanf("%d",&(*d).annee);
      }while((*d).annee==0);
     //l'annee ne doit pas t'egal a 0.
}
//Information sur le Paiement.
void info_Paiement(paiement *p)
{
  FILE* paie;
  FILE* etud;
  int id,idpp;
  paie=fopen("paiement.txt","a");
  if(paie == NULL)
  {
    printf("Erreur D'ouverture du Fichier \n");
    exit(EXIT_FAILURE);
  }
  if(etud == NULL)
  {
    printf("Erreur d'ouverture du fichier\n");
    exit(EXIT_FAILURE);
  }
  printf("Donner IDP : ");
  scanf("%d",&idpp);
  while(rechidp(idpp) == 1)
  {
    printf("Cette IDP est deja attribuer\n");
    printf("Veuiller Ressayer une autre\n");
    printf("IDP : ");
    scanf("%d",&idpp);
  }
  (*p).idp=idpp;
  //le Programme n'acceptera pas une montant negatif.
  do
  {
  printf("Donner le Montant : ");
  scanf("%lf",&(*p).montant);
  }while((*p).montant<0);
  saisie_Date(&p->datepaie);
  printf("Donner l'Objet: ");
  scanf("%s",(*p).objet);
  printf("Donner l'IDE de l'etudiant : ");
  scanf("%d",&id);
  while(rechide(id)== -1)
  {
    printf("Cette IDE existe pas dans la liste des Etudiants\n");
    printf("Donner votre IDE : ");
    scanf("%d",&id);
  }
  (*p).ide=id;
  //scanf("%d",&(*p).ide);
  fprintf(paie, "%d , %lf , %d/%d/%d , %s , %d\n",(*p).idp,(*p).montant,(*p).datepaie.jour,(*p).datepaie.mois,(*p).datepaie.annee,(*p).objet,(*p).ide);
  fclose(paie);
}
//Saisie du Paiement.
void saisie_Paiment(paiement f)
{
  unsigned int n;
  int i;
  do
  {
  printf("Donner le Nombre de Paiement a Enregistrer\n");
  scanf("%d",&n);
  }while(n<=0);
  for (i=0;i<n;i++)
  {
    info_Paiement(&f);
  }
}
//afficher les paiement disponibles sur la fichier paiement.txt
void afficher_Paiment(paiement t)
{
  FILE* paie;
  paie=fopen("paiement.txt","r");
  if(paie==NULL)
  {
    printf("Erreur d'ouverture \n");
    exit(EXIT_FAILURE);
  }
  printf("\nVoici La Liste des Paiements\n\n");

  do
  {
    fscanf(paie,"%d , %lf , %d/%d/%d , %s , %d\n",&t.idp,&t.montant,&t.datepaie.jour,&t.datepaie.mois,&t.datepaie.annee,&t.objet,&t.ide);
    printf("%d ,",t.idp);
    printf(" %lf Fcfa ,",t.montant);
    printf(" %d/%d/%d ,",t.datepaie.jour,t.datepaie.mois,t.datepaie.annee);
    printf(" %s ,",t.objet);
    printf(" %d\n",t.ide);
  }
  while(!feof(paie));
  fclose(paie);
}
//rechercher idp du paiement sur l'ensemble des paiement disponibles sur la fichier paiement.txt
void recherche_Paiement(paiement p)
{ FILE* paie;
  int IDP,trouve=0;
  paie=fopen("paiement.txt","r");
  if(paie==NULL)
  {
    printf("Erreur d'ouverture \n");
    exit(EXIT_FAILURE);
  }
  printf("Donner l'IDP a Chercher : ");
  scanf("%d",&IDP);
  do
  {
    fscanf(paie,"%d , %lf , %d/%d/%d , %s , %d\n",&p.idp,&p.montant,&p.datepaie.jour,&p.datepaie.mois,&p.datepaie.annee,&p.objet,&p.ide);
    if(p.idp==IDP)
    {
    printf("\nPaiement Trouve \n");
    printf("%d ,",p.idp);
    printf(" %lf Fcfa ,",p.montant);
    printf(" %d/%d/%d ,",p.datepaie.jour,p.datepaie.mois,p.datepaie.annee);
    printf(" %s ,",p.objet);
    printf(" %d\n",p.ide);
    trouve=trouve+1;
    }
  }while(!feof(paie));
  fclose(paie);
  if(trouve==0)
    {
      printf("\nCette IDP:%d n'existe pas dans la liste des Paiements\n",IDP);
    }
}
//Calcul la montant total des paiement enregistrer sur le fichier paiement.txt
double montant_Paiement_Total(paiement r)
{
  double total=0;
  FILE* paie;
  paie=fopen("paiement.txt","r");
  if(paie == NULL)
  {
    printf("Erreur D'ouverture du Fichier \n");
    exit(EXIT_FAILURE);
  }
  do
  {
   fscanf(paie,"%d , %lf , %d/%d/%d , %s , %d\n",&r.idp,&r.montant,&r.datepaie.jour,&r.datepaie.mois,&r.datepaie.annee,&r.objet,&r.ide);
   total=total+r.montant;
  }
  while(!feof(paie));
  fclose(paie);
  return total;
}
//Afficher la l'etuiant et les informations sur son paiements
void etat_paie_Etudiant(etudiant j,paiement l)
{
   FILE* paie;
   FILE* etud;
   int IDE;
   int trouv1=0,trouv2=0;
   paie=fopen("paiement.txt","r");
   etud=fopen("etudiant.txt","r");
  //On verifie Si la fichier etudiant.txt n'est pas Null.
   if(etud == NULL)
  {
    printf("Erreur D'ouverture du Fichier\n");
    exit(EXIT_FAILURE);
  }
  //On verirfie si la fichier paiement.txt n'
   if(paie == NULL)
  {
    printf("Erreur D'ouverture du Fichier\n");
    exit(EXIT_FAILURE);
  }
   printf("\nDonner l'IDE de L'etudiant : ");
   scanf("%d",&IDE);
   printf("\n");  
  //On parcours toute le fichier etudiant.txt pour voir si cette ide existe dans le fichier.
  //Et si c'est le cas On affiche l'etudiant concerne.
   do
  {
    fscanf(etud,"%d , %s , %s , %s\n",&j.ide,&j.prenom,&j.nom,&j.classe);
    if(j.ide==IDE)
    {
      printf("%d ",j.ide);
      printf("%s\t",j.prenom);
      printf("%s\t",j.nom);
      printf("%s\n",j.classe);
      //Si on trouve l'etudiant on incremente le compteur trouv1 a 1;
      trouv1=trouv1+1;
    }

  }while(!feof(etud));
  fclose(etud);
   //Si compteur trouv1 reste a 0 dons l'etudiant n'est dans le fichier etudiant.txt
  if(trouv1==0)
    {
      printf("\nCette IDE:%d n'existe pas dans la liste des Etudiants\n",IDE);
    }
   //On parcours toute le fichier paiement.txt pour voir si cette ide existe dans le fichier.
  //Et si c'est le cas On affiche le(s) paiement de l'etudiant concerne.
  do
  {
    fscanf(paie,"%d , %lf , %d/%d/%d , %s , %d\n",&l.idp,&l.montant,&l.datepaie.jour,&l.datepaie.mois,&l.datepaie.annee,&l.objet,&l.ide);
    if(l.ide==IDE)
    {
    printf("%d ,",l.idp);
    printf(" %lf Fcfa ,",l.montant);
    printf(" %d/%d/%d ,",l.datepaie.jour,l.datepaie.mois,l.datepaie.annee);
    printf(" %s ,",l.objet);
    printf(" %d\n",l.ide);
   //Si on trouve l'etudiant on incremente le compteur trouv2 a 1;
    trouv2=trouv2+1;
    }
  }while(!feof(paie));
  fclose(paie);
   //Si le compteur trouv2 reste a 0 l'etudiant n'est pas dans la liste des paiements.
  if(trouv2==0)
    {
      printf("\nCette IDE:%d n'existe pas dans la liste des Paiements\n",IDE);
    }
}
void rechercher_Un_Paiement_Par_IDE(paiement k)
{
  FILE* paie;
  int idee;
  int trouve=0;
  paie=fopen("paiement.txt","r");
  if (paie == NULL)
  {
    printf("Erreur d'ouverture du Fichier\n");
    exit(EXIT_FAILURE);
  }
  printf("Donner IDE: ");
  scanf("%d",&idee);
  do
  {
    fscanf(paie,"%d , %lf , %d/%d/%d , %s , %d\n",&k.idp,&k.montant,&k.datepaie.jour,&k.datepaie.mois,&k.datepaie.annee,&k.objet,&k.ide);
    if(k.ide==idee)
    {
    printf("Paiment Trouve\n");
    printf("%d ,",k.idp);
    printf(" %lf Fcfa ,",k.montant);
    printf(" %d/%d/%d ,",k.datepaie.jour,k.datepaie.mois,k.datepaie.annee);
    printf(" %s ,",k.objet);
    printf(" %d\n",k.ide);
    trouve=trouve+1;
   }
  }while(!feof(paie));
  fclose(paie);
  if(trouve==0)
  {
    printf("Cette IDE : %d n'existe pas dans la liste des Paiements\n",idee);
  }
}

int main()
{
  
 int choix;
 etudiant e;
 paiement p;
 double som;
  do 
  {
  printf("\n                                                                         MENU                                                              \n\n");
  printf("\n                                                                1.Ajouter des Etudiant                                                        \n");
  printf("\n                                                                2.Rechercher Un Etudiant                                                      \n");
  printf("\n                                                                3.Afficher la Liste des Etudiant                                               \n");
  printf("\n                                                                4.Afficher les Etudiants Par Classe                                             \n");
  printf("\n							        5.Enregistrer des Paiements                                                      \n");
  printf("\n                                                                6.Afficher les Paiements                                                          \n");
  printf("\n                                                                7.Rechercher un Paiement par IDP                                                         \n");
  printf("\n                                                                8.Montant Total des Paiements                                                       \n");
  printf("\n                                                                9.Etat de Paiement d'un Etudiant                                                     \n");
  printf("\n                                                                10.Rechercher Un Paiement par IDE                                                          \n");
  printf("\n                                                                11.QUITTER                                                                                 \n");
  printf("\n");
  printf("\n                                                                 Donner votre choix : "                                                              );
  scanf("%d",&choix);
  switch(choix)
  {
  case 1:
  {
  saisie_Etudiant(e);
  break;
  }
  case 2:
  {
    printf("\n                                                               1.Recherche par IDE                                                                     \n");
    printf("\n                                                               2.Recherche par NOM                                                                     \n");
    printf("\n");
    printf("Donner votre choix : ");
    scanf("%d",&choix);
    switch(choix)
    {
    case 1:
    {
      rechercher_IDE(e);
      break;
    }
    case 2:
    {
      rechercher_NOM(e);
      break;
    }
    default:
    printf("Mauvaise Saisie!!!!!!\n");
    printf("Ressayer Encore\n");
    break;
    }
    break;
  }
  case 3:
  {
    afficher_Etudiant(e);
    break;
  }
  case 4:
  {
    etudiant_par_classe(e);
    break;
  }
  case 5:
  {
    saisie_Paiment(p);
    break;
  }
  case 6:
  {
    afficher_Paiment(p);
    break;
  }
  case 7:
  {
    recherche_Paiement(p);
    break;
  }
  case 8:
  {
    som=montant_Paiement_Total(p);
    printf("Le Montant Total de tous les Paiements est : %lf Fcfa\n",som); 
    break;
  }
  case 9:
  {
     etat_paie_Etudiant(e,p);
    break;
  }
  case 10:
  {
    rechercher_Un_Paiement_Par_IDE(p);
    break;
  }
  case 11:
  {
    printf("Au revoir\n");
    return 0;
    break;
  }
   default:
   printf("Mauvaise Saisie Veuiller Essayer encore\n");
   break;
}
}while(choix<11 || choix >11);
  
}
