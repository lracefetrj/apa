#ifndef _LISTA_H_
#define _LISTA_H_

#include <stdlib.h>
#include <stdio.h>

long int __lst_size = 0;

typedef struct list List;

struct list {
    int info;
    
    List *next;
};

List *lst_create (void)
{
    return NULL;
}

long int lst_size (void)
{
    return __lst_size;
}

List *lst_add (List *lst, int data)
{
    List *tmp = (List *) malloc (sizeof (List));
    
    if (tmp == NULL)
        return lst;
    
    tmp->info = data;
    tmp->next = lst;
    
    lst = tmp;
    
    __lst_size++;
    
    return lst;
}

List *lst_add_ord (List *lst, int data)
{
    List *ant = NULL;
    List *tmp = lst;
    
    while (tmp != NULL && tmp->info < data)
    {
        ant = tmp;
        tmp = tmp->next;
    }
    
    List *p = (List *) malloc (sizeof (List));
    
    if (p == NULL)
        return lst;
    
    p->info = data;
    p->next = tmp;
    
    if (ant == NULL)
    {
        lst = p;
    }
    else
    {
        ant->next = p;
    }
    
    __lst_size++;
    
    return lst;
}

int lst_search (List *lst, int data)
{
    if (lst == NULL)
        return 0;
    
    List *tmp = lst;
    while (tmp != NULL)
    {
        
        if (tmp->info == data)
            return 1;
        
        tmp = tmp->next;
    }
    
    return 0;
}

List *lst_exchange_info (List *lst, int d1, int d2)
{
    
    if (lst == NULL)
        return lst;
    
    if (d1 == d2)
        return lst;
    
    List *tmp = lst;
    List *ant = NULL, *a1 = NULL, *a2 = NULL;
    int e1 = 0, e2 = 0;
    
    while (tmp != NULL && (a1 == NULL || a2 == NULL))
    {
        
        if (tmp->info == d1)
        {
            a1 = ant;
            e1 = 1;
        }
        
        if (tmp->info == d2)
        {
            a2 = ant;
            e2 = 1;
        }
        ant = tmp;
        tmp = tmp->next;
    }
    
    if (e1 == 0 || e2 == 0)
        return lst;
    
    if (a1 == NULL)
    {
        List *a3 = lst;
        List *a5 = a3->next;
        
        List *a4 = a2->next;
        List *a6 = a4->next;
        
        if (a3->next == a4)
        {
            a4->next = a2;
            a2->next = a6;
        }
        else
        {
            a4->next = a5;
            a2->next = a3;
            a3->next = a6;
        }
        
        lst = a4;
    }
    else if (a2 == NULL)
    {
        
        List *a4 = lst;
        List *a6 = a4->next;
        
        List *a3 = a1->next;
        List *a5 = a3->next;
        
        if (a4->next == a3)
        {
            a3->next = a1;
            a1->next = a5;
        }
        else
        {
            a3->next = a6;
            a1->next = a4;
            a4->next = a5;
        }
        
        lst = a3;
    }
    else
    {
        List *a3 = a1->next;
        List *a5 = a3->next;
        
        List *a4 = a2->next;
        List *a6 = a4->next;
        
        if (a1->next == a2)
        {
            a1->next = a4;
            a4->next = a2;
            a2->next = a6;
        }
        else if (a2->next == a1)
        {
            a2->next = a3;
            a3->next = a1;
            a1->next = a5;
        }
        else
        {
            a1->next = a4;
            a4->next = a5;
            a2->next = a3;
            a3->next = a6;
        }
        
    }
    
    return lst;
}

List *lst_move_menor (List *lst)
{
    
    if (NULL == lst)
        return lst;
    
    List *tmp = lst, *ant = NULL, *a1 = NULL;
    int e1 = INT32_MAX;
    
    while (tmp != NULL)
    {
        
        if (tmp->info < e1)
        {
            a1 = ant;
            e1 = tmp->info;
        }
        
        ant = tmp;
        tmp = tmp->next;
    }
    
    if (a1 == NULL)
        return lst;
    
    List *a3 = lst;
    List *a5 = a3->next;
    
    List *a4 = a1->next;
    List *a6 = a4->next;
    
    if (a3->next == a4)
    {
        a4->next = a1;
        a1->next = a6;
    }
    else
    {
        a4->next = a5;
        a1->next = a3;
        a3->next = a6;
    }
    
    lst = a4;
    
    return (lst);
}

List *lst_remove (List *lst, int data)
{
    
    if (lst == NULL)
        return lst;
    
    List *ant = NULL;
    List *tmp = lst;
    
    while (tmp != NULL && tmp->info != data)
    {
        
        ant = tmp;
        tmp = tmp->next;
    }
    
    if (ant == NULL)
    {
        lst = lst->next;
    }
    else
    {
        ant->next = tmp->next;
    }
    
    free (tmp);
    
    __lst_size--;
    
    return lst;
}

void lst_print (List *lst)
{
    if (lst == NULL)
        return;
    
    List *tmp = lst;
    while (tmp != NULL)
    {
        printf ("%d  ", tmp->info);
        tmp = tmp->next;
    }
    printf ("\n");
}

List *lst_destroy (List *lst)
{
    if (lst == NULL)
        return lst;
    
    List *tmp = NULL;
    
    while (lst != NULL)
    {
        tmp = lst->next;
        free (lst);
        lst = tmp;
    }
    
    return NULL;
}

#endif //_LISTA_H_
