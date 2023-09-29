#PART I- Data Preprocessing Template

# Importing the libraries
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

#IMPORTING THE DATASET
dataset=pd.read_csv('Salary_Data.csv')

#CREATING MATRIX OF DATASET
X=dataset.iloc[:, :-1].values
Y=dataset.iloc[:, 1].values

#SPLITTING THE DATASET INTO THE TRAINING SET AND TEST SET
from sklearn.model_selection import train_test_split
X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size = 1/3, random_state = 0)

#FEATURE SCALING
"""from sklearn.preprocessing import StandardScaler
sc_X = StandardScaler()
X_train = sc_X.fit_transform(X_train)
X_test = sc_X.transform(X_test)"""

#PART II- Regressions

#SIMPLE LINEAR REGRESSION

# fitting linear regression to the training set
from sklearn.linear_model import LinearRegression
regressor = LinearRegression()
regressor.fit(X_train, Y_train)

# predicting the test set results
Y_pred = regressor.predict(X_test)

# visualising the training set results
plt.scatter(X_train, Y_train, color='pink')
plt.plot(X_train, regressor.predict(X_train), color='black')
plt.title('Salary vs Years of Experience (Training Set)')
plt.xlabel('Years of Experience')
plt.ylabel('Salary')
plt.show()

# Visualising the test set results
plt.scatter(X_test, Y_test, color='orange')
plt.plot(X_test, Y_pred, color='blue')
plt.title('Salary vs Years of Experience (Test Set)')
plt.xlabel('Years of Experience')
plt.ylabel('Salary')
plt.show()





