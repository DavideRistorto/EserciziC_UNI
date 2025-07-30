setwd("C:/Users/Davide/Desktop/Scuola/EserciziC_UNI/Statistica/Esercizi_Esami/ES1")

load("ricerca.RData") # carico il data-set
str(dati)             # descrizione compatta delle colonne dei dati -> colonna algoritmo e tempo
head(dati)            # visualizzo le prime righe dei dati
table(dati$algoritmo) #calcolo la frequenza per i valori distinti di una colonna
mean(dati$tempo[dati$algoritmo == 'alg_A'])   # calcolo la media dei tempi solo degli algoritmi di tipo A
sd(dati$tempo[dati$algoritmo == 'alg_A'])     # calcolo la deviazione standard dei tempi solo degli algoritmi di tipo A
quantile(dati$tempo[dati$algoritmo == 'alg_A'], 0.95) #calcolo il 5% degli algoritmi più lenti, ovvero il 95 percentile

#intervallo di confidenza per la stima delle medie dei vari algoritmi
t.test(dati$tempo[dati$algoritmo == 'alg_A'], conf.level = 0.99)  
t.test(dati$tempo[dati$algoritmo == 'alg_B'], conf.level = 0.99)

# i valori degli intervalli si intrecciano, quindi è possibile che abbiano la stessa media

# grafico
boxplot(tempo ~ algoritmo, 
        data = dati,
        main = "Confronto Tempi di Risposta: alg_A vs alg_B",
        xlab = "Algoritmo",
        ylab = "Tempo (ms)",
        col = c("lightblue", "salmon"))
