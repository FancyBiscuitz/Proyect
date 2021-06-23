#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <ctime>

#include "user.h"
#include "item.h"
#include "product.h"
#include "utils.h"
#include "admin.h"
#include "client.h"
#include "purchase.h"
#include "bill.h"

using namespace std;

int main(void)
{
   /*
    while (!logged)
    {
        1. register
        2. login
        3. exit
    }
    string role = verificar si es admin o client
    instanciar usuario
    if (role == client)
    {
        cargar carrito de compras 
    }
    while (true)
    {
        int choice = menu principal(admin o client):
        switch (role)
        {
            case client
            {
            do
            {
                switch
                {
                    ver productos 
                    filtrar productos 
                    anadir productos a carrito
                    eliminar productos de carrito
                    ver carrito 
                    comprar
                    regresar
                    cerrar sesion
                }
            } while (choice is invalid)
            }
            
            case admin
            {
                do 
                {
                    switch
                    {
                        añadir productos
                        eliminar productos
                        cambiar precio
                        cambiar stock
                        cambiar descuento
                        regresar
                        cerrar sesion  
                    }
                }while (choice is invalid)
            }
            
        }
    }
   */
    Client cliente;
    cliente.setId("testid");
    std::vector<Purchase> billData;
    cliente.addProductsToShoppingCart();
    
    for (int i = 0; i < cliente.getShoppingCart().size(); i++)
    {
        Purchase compra(cliente.getShoppingCart()[i], cliente.getQuantity()[i], cliente.getId());
        billData.push_back(compra);
    }
    for (int j = 0; j < cliente.getShoppingCart().size(); j++)
    {
        std::cout << cliente.getShoppingCart()[j].getId() << std::endl;
    }
    Bill factura(billData);
    if (factura.validateBill(cliente))
    {
        factura.processBill(cliente);
    }
}