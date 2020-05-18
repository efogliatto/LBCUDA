import numpy as np
import matplotlib.pyplot as plt
import MaxwellConstruction as mx
import collections

#%%

if __name__ == "__main__":

    def ordToList( dict ):
    
        col = collections.OrderedDict(sorted(dict.items()))

        x = []
        
        y = []
    
        for k,v in col.items():

            x.append(k)
            y.append(v)

        return x,y

    # Arreglo con los valores de temperatura reducida para calcular las densidades de coexistencia

    TEos = np.concatenate( [np.arange(0.6,0.925,0.025) , np.array([0.925, 0.95, 0.975, 0.99, 0.995]) ] )
    
    # Curva de coexistencia de Van Der Waals

    vdw = mx.EOS('VanDerWaals', a=0.5, b=4.0)

    # Diccionario para facilitar el grafico: coex{ rho_r : T_r  }
    
    coex = {1:1}

    # Calculo de densidades de coexistencia para las teperaturas reducidas de TEos
    # Como se grafican valores reducidos (adimensionales), la curva es universal: no depende de las constantes a y b

    for i,T in enumerate(TEos):


        # Argumento necesario para la integracion de la EOS a T bajas
        
        step = 0.999
        if T < 0.6:
            step = 0.9999


        # Calculo de volumen reducido

        Vrmin,Vrmax = mx.coexistencia(vdw, T, plotPV=False, step_size=step)

        coex[1/Vrmin] = T
        coex[1/Vrmax] = T


    # Ordenamiento de coex para graficacion
        
    coex = ordToList( collections.OrderedDict(sorted(coex.items())) )

#    plt.plot(coex[0], coex[1], label='VdW')


#%%     Datos obtenidos de MaxwellConstruction para mesh = 100 x 100 tiempo 50000

lst = [ '6','625','65','675','7','725','75','775','8','825','85','875','9','925','95','975' ]
number = len(lst)

rhoc =  vdw.rhoc()

rhol_125 = []
rhog_125 = []
rhol_2 = []
rhog_2 = []
rhol_075 = []
rhog_075 = []


for idx in range(0,len(lst)):

    #rhol_125.append( np.max(np.loadtxt('/home/coronelth/DATOSLB_VAL_SUP/validacion_MxC_sigma_0_125_1.0/'+lst[idx] +'/rhoaux',np.float32) ) ) 
    #rhog_125.append( np.min(np.loadtxt('/home/coronelth/DATOSLB_VAL_SUP/validacion_MxC_sigma_0_125_1.0/'+lst[idx] +'/rhoaux',np.float32) ) ) 
    rhol_125.append( np.max(np.loadtxt('/home/coronelth/DATOSLB_VAL_SUP/validacion_MxC_1.0/'+lst[idx] +'/rhoaux',np.float32) ) ) 
    rhog_125.append( np.min(np.loadtxt('/home/coronelth/DATOSLB_VAL_SUP/validacion_MxC_1.0/'+lst[idx] +'/rhoaux',np.float32) ) ) 
    
    rhol_2.append( np.max(np.loadtxt('/home/coronelth/DATOSLB_VAL_SUP/validacion_MxC_sigma_0_2_1.0/'+lst[idx] +'/rhoaux',np.float32) ) ) 
    rhog_2.append( np.min(np.loadtxt('/home/coronelth/DATOSLB_VAL_SUP/validacion_MxC_sigma_0_2_1.0/'+lst[idx] +'/rhoaux',np.float32) ) ) 
    
    rhol_075.append( np.max(np.loadtxt('/home/coronelth/DATOSLB_VAL_SUP/validacion_MxC_sigma_0_075_1.0/'+lst[idx] +'/rhoaux',np.float32) ) ) 
    rhog_075.append( np.min(np.loadtxt('/home/coronelth/DATOSLB_VAL_SUP/validacion_MxC_sigma_0_075_1.0/'+lst[idx] +'/rhoaux',np.float32) ) ) 

Tr = np.arange(0.6,1.0,0.025)
Tr = np.concatenate([Tr,Tr])

rhor_125 = np.concatenate([rhol_125,rhog_125])
rhor_2 = np.concatenate([rhol_2,rhog_2])
rhor_075 = np.concatenate([rhol_075,rhog_075])



#%%

plt.figure()

plt.plot(rhor_125/rhoc,Tr,'r.',ms=15)
plt.plot(rhor_2/rhoc,Tr,'c.',ms=15)
plt.plot(rhor_075/rhoc,Tr,'k.',ms=15)
plt.plot(coex[0], coex[1], label='VdW',linewidth=2.5)
plt.ylabel(r'$T/T_c$',fontsize=14)
plt.xlabel(r'$\rho/\rho_c$',fontsize=14)
plt.xscale('log')
plt.legend(loc = 'best', framealpha=1)
plt.xticks(fontsize=14)
plt.yticks(fontsize=14)
plt.grid(True)
plt.axis([0.05,2.95, 0.58,1.02])
#plt.savefig('validacion_MxC_Tr_rhor_201_201_tres_sigma_101.png')
plt.show()

plt.close
    
    
