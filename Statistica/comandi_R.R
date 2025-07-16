################################################################################
#                                                                              #
#                 COMANDI BASE RSTUDIO PER ESERCIZI DI STATISTICA             #
#                                                                              #
#############################################################################
############################################################################## I. GESTIONE DEI DATI                                                          #
################################################################################

# --- Importazione Dati ---
load("nome_del_file.RData")
#   Descrizione: Carica gli oggetti (es., data frame) da un file .RData.
#   Esempio: load("dati_esempio.RData")


# --- Visualizzazione Dati ---
head(nome_del_data_frame)
#   Descrizione: Mostra le prime righe del data frame (default 6).
#   Esempio: head(miei_dati)

tail(nome_del_data_frame)
#   Descrizione: Mostra le ultime righe del data frame (default 6).
#   Esempio: tail(miei_dati)

str(nome_del_data_frame)
#   Descrizione: Mostra la struttura interna del data frame (tipi di variabile, ecc.).
#   Esempio: str(miei_dati)

summary(nome_del_data_frame)
#   Descrizione: Mostra un riassunto statistico del data frame (media, mediana, ecc.).
#   Esempio: summary(miei_dati)

nrow(nome_del_data_frame)
#  Descrizione: Restituisce il numero di righe (osservazioni) del data frame.
#   Esempio: nrow(miei_dati)
names(nome_del_data_frame)
# Descrizione: Restituisce i nomi delle colonne del data frame.
#   Esempio: names(miei_dati)

# --- Selezione Colonne ---
nome_del_data_frame$nome_della_colonna
# Descrizione: Seleziona una specifica colonna dal data frame.
#   Esempio: miei_dati$eta

# --- Filtro Dati ---
nome_del_data_frame[nome_del_data_frame$nome_colonna == "valore", ]
# Descrizione: Restituisce le righe dove la colonna è uguale al valore.
#   Esempio: miei_dati[miei_dati$sesso == "Femmina", ]

nome_del_data_frame[nome_del_data_frame$nome_colonna > valore, ]
# Descrizione: Restituisce le righe dove la colonna è maggiore del valore.
#   Esempio: miei_dati[miei_dati$eta > 30, ]

nome_del_data_frame[nome_del_data_frame$nome_colonna < valore, ]
# Descrizione: Restituisce le righe dove la colonna è minore del valore.
#   Esempio: miei_dati[miei_dati$punteggio < 10, ]

# --- Rimozione Valori Mancanti ---
nome_del_data_frame[complete.cases(nome_del_data_frame),]
# Descrizione: Restituisce un data frame senza le righe contenenti valori mancanti.
#   Esempio: dati_puliti <- miei_dati[complete.cases(miei_dati),]

# --- Tabulazione di Frequenze ---
table(nome_del_data_frame$nome_colonna)
# Descrizione: Calcola la frequenza assoluta delle categorie in una colonna.
#   Esempio: table(miei_dati$gruppo_sanguigno)

prop.table(table(nome_del_data_frame$nome_colonna))
# Descrizione: Calcola la frequenza relativa (proporzioni) delle categorie in una colonna.
#  Esempio: prop.table(table(miei_dati$gruppo_sanguigno))

# --- Conteggio Valori Mancanti ---
sum(is.na(nome_del_data_frame$nome_colonna))
# Descrizione: Restituisce il numero di valori mancanti in una colonna.
#   Esempio: sum(is.na(miei_dati$punteggio))


################################################################################
# II. STATISTICHE DESCRITTIVE                                                   #
################################################################################

# --- Misure di Tendenza Centrale e Dispersione ---
mean(nome_del_data_frame$nome_colonna)
# Descrizione: Calcola la media di una colonna.
#   Esempio: mean(miei_dati$altezza)

sd(nome_del_data_frame$nome_colonna)
# Descrizione: Calcola la deviazione standard di una colonna.
#   Esempio: sd(miei_dati$peso)

# --- Quantili (Percentili) ---
quantile(nome_del_data_frame$nome_colonna, probs = c(0.25, 0.5, 0.75))
# Descrizione: Calcola i quartili (25°, 50°, 75°) di una colonna.
#   Esempio: quantile(miei_dati$punteggio, probs = c(0.25, 0.5, 0.75))

quantile(nome_del_data_frame$nome_colonna, probs = 0.95)
# Descrizione: Calcola il 95° percentile di una colonna.
#   Esempio: quantile(miei_dati$punteggio, probs = 0.95)
quantile(nome_del_data_frame$nome_colonna, probs = 0.05)
# Descrizione: Calcola il 5° percentile di una colonna.
#   Esempio: quantile(miei_dati$punteggio, probs = 0.05)

# --- Valori Minimi e Massimi ---
min(nome_del_data_frame$nome_colonna)
# Descrizione: Trova il valore minimo di una colonna.
#   Esempio: min(miei_dati$temperatura)

max(nome_del_data_frame$nome_colonna)
# Descrizione: Trova il valore massimo di una colonna.
#   Esempio: max(miei_dati$temperatura)


################################################################################
# III. VISUALIZZAZIONE GRAFICA                                                #
################################################################################

# --- Istogramma ---
hist(nome_del_data_frame$nome_colonna, breaks = numero_intervalli, main = "Titolo", xlab = "Etichetta asse x", ylab = "Etichetta asse y")
# Descrizione: Crea un istogramma per visualizzare la distribuzione di una colonna.
#   Esempio: hist(miei_dati$eta, breaks = 10, main="Distribuzione Età", xlab = "Età (anni)", ylab = "Frequenza")


# --- Boxplot ---
boxplot(nome_del_data_frame$nome_colonna, main = "Titolo", ylab = "Etichetta asse y")
# Descrizione: Crea un singolo boxplot per una colonna.
#  Esempio: boxplot(miei_dati$punteggio, main = "Boxplot Punteggi", ylab = "Punteggio")

boxplot(nome_del_data_frame$nome_colonna ~ nome_del_data_frame$nome_gruppo, names = c("gruppo1", "gruppo2"), main = "Titolo", ylab = "Etichetta asse y", xlab = "Etichetta asse x")
# Descrizione: Crea boxplot separati per gruppi (utilizzando un'altra colonna).
#   Esempio: boxplot(miei_dati$punteggio ~ miei_dati$sesso, main = "Confronto Punteggi per Sesso", ylab = "Punteggio", xlab = "Sesso", names=c("Femmine","Maschi"))

# --- Barplot
barplot(table(nome_del_data_frame$nome_colonna), main = "Titolo", xlab = "Etichetta asse x", ylab = "Etichetta asse y")
# Descrizione: Crea un barplot per una colonna con valori discreti
# Esempio: barplot(table(miei_dati$colore), main = "Barplot Colori", xlab = "Colore", ylab = "Frequenza")


################################################################################
# IV. TEST DI IPOTESI                                                          #
################################################################################

# --- T-test (confronto con un valore) ---
t.test(nome_del_data_frame$nome_colonna, mu = valore_di_riferimento, alternative = "two.sided")
# Descrizione: T-test con ipotesi alternativa bilaterale (la media è diversa dal valore).
#   Esempio: t.test(miei_dati$punteggio, mu = 10, alternative = "two.sided")

t.test(nome_del_data_frame$nome_colonna, mu = valore_di_riferimento, alternative = "less")
# Descrizione: T-test con ipotesi alternativa unilaterale (la media è minore del valore).
#   Esempio: t.test(miei_dati$punteggio, mu = 10, alternative = "less")

t.test(nome_del_data_frame$nome_colonna, mu = valore_di_riferimento, alternative = "greater")
# Descrizione: T-test con ipotesi alternativa unilaterale (la media è maggiore del valore).
#   Esempio: t.test(miei_dati$punteggio, mu = 10, alternative = "greater")


# --- T-test (due campioni indipendenti) ---
t.test(nome_del_data_frame$nome_colonna[nome_del_data_frame$nome_gruppo == "gruppo1"],
       nome_del_data_frame$nome_colonna[nome_del_data_frame$nome_gruppo == "gruppo2"],
       alternative = "two.sided")
# Descrizione: T-test per due campioni indipendenti con alternativa bilaterale.
#   Esempio: t.test(miei_dati$punteggio[miei_dati$gruppo == "A"], miei_dati$punteggio[miei_dati$gruppo == "B"], alternative = "two.sided")

t.test(nome_del_data_frame$nome_colonna[nome_del_data_frame$nome_gruppo == "gruppo1"],
       nome_del_data_frame$nome_colonna[nome_del_data_frame$nome_gruppo == "gruppo2"],
       alternative = "less")
# Descrizione: T-test per due campioni indipendenti con alternativa unilaterale (minore).
#   Esempio: t.test(miei_dati$punteggio[miei_dati$gruppo == "A"], miei_dati$punteggio[miei_dati$gruppo == "B"], alternative = "less")

t.test(nome_del_data_frame$nome_colonna[nome_del_data_frame$nome_gruppo == "gruppo1"],
       nome_del_data_frame$nome_colonna[nome_del_data_frame$nome_gruppo == "gruppo2"],
       alternative = "greater")
# Descrizione: T-test per due campioni indipendenti con alternativa unilaterale (maggiore).
#   Esempio: t.test(miei_dati$punteggio[miei_dati$gruppo == "A"], miei_dati$punteggio[miei_dati$gruppo == "B"], alternative = "greater")

# --- T-test (due campioni appaiati) ---
t.test(nome_del_data_frame$nome_colonna_1,
       nome_del_data_frame$nome_colonna_2,
       paired = TRUE,
       alternative = "two.sided")
# Descrizione: T-test per due campioni appaiati con alternativa bilaterale.
#   Esempio: t.test(miei_dati$punteggio_pre, miei_dati$punteggio_post, paired = TRUE, alternative = "two.sided")

t.test(nome_del_data_frame$nome_colonna_1,
       nome_del_data_frame$nome_colonna_2,
       paired = TRUE,
       alternative = "less")
# Descrizione: T-test per due campioni appaiati con alternativa unilaterale (minore).
#  Esempio: t.test(miei_dati$punteggio_pre, miei_dati$punteggio_post, paired = TRUE, alternative = "less")

t.test(nome_del_data_frame$nome_colonna_1,
       nome_del_data_frame$nome_colonna_2,
       paired = TRUE,
       alternative = "greater")
# Descrizione: T-test per due campioni appaiati con alternativa unilaterale (maggiore).
# Esempio: t.test(miei_dati$punteggio_pre, miei_dati$punteggio_post, paired = TRUE, alternative = "greater")


# --- Test Binomiale (per proporzioni) ---
binom.test(x = numero_di_successi,
           n = numero_di_prove,
           p = valore_sotto_H0,
           alternative = "two.sided")
# Descrizione: Test binomiale con ipotesi alternativa bilaterale.
#   Esempio: binom.test(x = 60, n = 100, p = 0.5, alternative = "two.sided")

binom.test(x = numero_di_successi,
           n = numero_di_prove,
           p = valore_sotto_H0,
           alternative = "less")
# Descrizione: Test binomiale con ipotesi alternativa unilaterale (minore).
#  Esempio: binom.test(x = 60, n = 100, p = 0.5, alternative = "less")

binom.test(x = numero_di_successi,
           n = numero_di_prove,
           p = valore_sotto_H0,
           alternative = "greater")
# Descrizione: Test binomiale con ipotesi alternativa unilaterale (maggiore).
#   Esempio: binom.test(x = 60, n = 100, p = 0.5, alternative = "greater")


################################################################################
# V. INTERVALLI DI CONFIDENZA                                                   #
################################################################################

# --- Intervalli di Confidenza per la Media ---
t.test(nome_del_data_frame$nome_colonna, conf.level = livello_di_confidenza)
# Descrizione: Calcola l'intervallo di confidenza per la media.
#   Esempio: t.test(miei_dati$eta, conf.level = 0.95)


################################################################################
# VI. DISTRIBUZIONI DI PROBABILITÀ                                             #
################################################################################

# --- Normale ---
dnorm(x, mean = media, sd = deviazione_standard)
# Descrizione: Calcola la densità della distribuzione normale.
#  Esempio: dnorm(1.96, mean = 0, sd = 1)

pnorm(x, mean = media, sd = deviazione_standard)
# Descrizione: Calcola la funzione di ripartizione della distribuzione normale.
#  Esempio: pnorm(1.96, mean = 0, sd = 1)

# --- Esponenziale ---
dexp(x, rate = parametro_rate)
# Descrizione: Calcola la densità della distribuzione esponenziale.
#  Esempio: dexp(2, rate = 0.5)

pexp(x, rate = parametro_rate)
# Descrizione: Calcola la funzione di ripartizione della distribuzione esponenziale.
#  Esempio: pexp(2, rate = 0.5)

# --- Uniforme ---
dunif(x, min = limite_inferiore, max = limite_superiore)
# Descrizione: Calcola la densità della distribuzione uniforme.
#  Esempio: dunif(0.5, min = 0, max = 1)

punif(x, min = limite_inferiore, max = limite_superiore)
# Descrizione: Calcola la funzione di ripartizione della distribuzione uniforme.
#   Esempio: punif(0.5, min = 0, max = 1)

# --- Binomiale ---
dbinom(x, size = numero_di_prove, prob = probabilità_di_successo)
# Descrizione: Calcola la probabilità che un evento accada un dato numero di volte in un numero di tentativi.
# Esempio: dbinom(2, size = 5, prob = 0.3)

################################################################################
# VII. CALCOLO COMBINATORIO                                                     #
################################################################################

# --- Coefficiente Binomiale ---
choose(n, k)
# Descrizione: Calcola il coefficiente binomiale ("n su k").
#   Esempio: choose(5, 2)

# --- Fattoriale ---
factorial(n)
# Descrizione: Calcola il fattoriale di un numero n.
#   Esempio: factorial(4)