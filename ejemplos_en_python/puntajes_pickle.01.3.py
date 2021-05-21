#! /usr/bin/env python
# encoding: utf8

import pickle

def guardar_puntajes(nombre_archivo, puntajes):
    """ Guarda la lista de puntajes en el archivo.
    Pre: nombre_archivo corresponde a un archivo válido,
         puntajes corresponde a una lista de tuplas de 3 elementos.
    Post: se guardaron los valores en el archivo,
          separados por comas.
    """
    archivo = open(nombre_archivo, "wb")
    pickle.dump(puntajes, archivo)
    archivo.close()

def recuperar_puntajes(nombre_archivo):
    """ Recupera los puntajes a partir del archivo provisto.
        Devuelve una lista con los valores de los puntajes.
    Pre: el archivo contiene los puntajes en el formato esperado,
         separados por comas
    Post: la lista devuelta contiene los puntajes en el formato:
          [(nombre1,puntaje1,tiempo1),(nombre2,puntaje2,tiempo2)].
    """
    archivo = open(nombre_archivo, "rb")
    puntajes = pickle.load(archivo)
    archivo.close()
    return puntajes

valores = [("Pepe", 108, "4:16"), ("Juana", 2315, "8:42")]
guardar_puntajes("puntajes.dat", valores)
print (recuperar_puntajes("puntajes.dat"))
