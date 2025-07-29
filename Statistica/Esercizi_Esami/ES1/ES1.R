# Carica il dataset (assicurati di essere nella directory corretta)
load("ricerca.RData")
# Visualizza la struttura dei dati per capire cosa contiene
str(dati)   # Mostra struttura del dataset
head(dati)  # Mostra le prime righe

table(dati$algoritmo) #calcolo frequenza assoluta di una colonna, in questo caso il numero di volte in cui sono stati usati gli algoritmi

mean(dati$tempo[dati$algoritmo == "alg_A"]) #media dei valori di tempo, filtrati solo per l' algoritmo A
sd(dati$tempo[dati$algoritmo == "alg_A"])   #deviazione standard dei valori di tempo, filtrati solo per l' algoritmo A

quantile(dati$tempo[dati$algoritmo == "alg_A"], 0.95) #Il 5% dei tempi di risposta più lenti dell'algoritmo A. Questo valore è il 95° percentile della distribuzione


boxplot(tempo ~ algoritmo, 
        data = dati,
        main = "Confronto Tempi di Risposta: alg_A vs alg_B",
        xlab = "Algoritmo",
        ylab = "Tempo (ms)",
        col = c("lightblue", "salmon"))

#Calcolo due intervalli di confidenza e li confronto.
t.test(dati$tempo[dati$algoritmo == "alg_A"], conf.level = 0.99) #Specifica che l'intervallo di confidenza deve essere calcolato al 99%
t.test(dati$tempo[dati$algoritmo == "alg_B"], conf.level = 0.99)
