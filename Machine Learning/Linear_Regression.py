import pandas as pd
#from sklearn.ensemble import RandomForestRegressor
#from sklearn.tree import DecisionTreeRegressor
from sklearn import preprocessing
from sklearn.linear_model import LinearRegression
import csv
#from sklearn.linear_model import  LinearRegression


le=preprocessing.LabelEncoder()

#['PassengerId', 'Survived', 'Pclass', 'Name', 'Sex', 'Age', 'SibSp','Parch', 'Ticket', 'Fare',]




path1="train_copy.csv"
path2="test.csv"

train_data=pd.read_csv(path1)
#print(train_data.columns)

features= [ 'Pclass','Sex', 'Age', 'SibSp','Parch','Fare']

#for column_name in train_data.columns:
        #if train_data[column_name].dtype == object:
            #train_data[column_name] = le.fit_transform(train_data[column_name])
        #else:
            #pass




train_y=train_data.Survived
train_x_sample=train_data.fillna(train_data.mean())
train_x=train_x_sample[features]

for val in train_x["Sex"]:
    if val=="male":
        train_x["Sex"]=train_x["Sex"].replace({"male":0})
    else:
        train_x["Sex"] = train_x["Sex"].replace({"female": 1})


print(train_x.head())




model=LinearRegression()

model.fit(train_x,train_y)

test_data=pd.read_csv(path2)

for column_name in test_data.columns:
        if test_data[column_name].dtype == object:
            test_data[column_name] = le.fit_transform(test_data[column_name])
        else:
            pass

test_x_sample=test_data.fillna(test_data.mean())

for val in test_x_sample["Sex"]:
    if val=="male":
        test_x_sample["Sex"]=test_x_sample["Sex"].replace({"male":0})
    else:
        test_x_sample["Sex"] = test_x_sample["Sex"].replace({"female": 1})


print("\nSpace\n")

print(test_x_sample.head())
test_x=test_x_sample[features]

predict_y=model.predict(test_x)

Survived = pd.DataFrame(predict_y, columns=['Survived']).to_csv('C:/Users/Arjun K Haridas/Desktop/ML/Titanic/prediction.csv')

prediction=pd.read_csv('C:/Users/Arjun K Haridas/Desktop/ML/Titanic/prediction.csv')
for val in prediction["Survived"]:
    if val>=0.5:
        prediction.replace(to_replace=val,value=1,inplace=True)
    else:
        prediction.replace(to_replace=val, value=0, inplace=True)

prediction.to_csv('outputfile.csv',
                 index = False)
