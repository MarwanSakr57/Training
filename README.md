# **Neural Network from Scratch**
This project is a simple implementation of a neural network built from scratch, designed to showcase the fundamental steps in neural network construction.
The code is implemented using Python and core data science libraries like NumPy, Matplotlib, and Pandas.
## **Overview:**
* this network is trained using the MNIST dataset
* it recognises digits from handdrawn samples
* it has about 85% accuracy
## **Example code:**
### 1.Loading the dataset as pandas then converting it to numpy array to easily mainpulate and flip it
```python
data_1 = pd.read_csv('mnist_train.csv')
data_2 = pd.read_csv('mnist_test.csv')
```
```python
data1 = np.array(data_1)
data2 = np.array(data_2)
m,n =data1.shape
l,k =data2.shape

np.random.shuffle(data1)
np.random.shuffle(data2)

data_train = data1.T
Y_train = data_train[0]
X_train = data_train[1:n]
X_train = X_train / 255.
_,m_train = X_train.shape

data_dev =data2.T#transposing the matrix
Y_dev =data_dev[0]
X_dev =data_dev[1:k]
X_dev = X_dev / 255.
```
### 2. Forward propagation:
```python
def forward_prop(W1, b1, W2, b2, X):#forward propagation function
    Z1 = W1.dot(X) + b1
    A1 = ReLU(Z1)
    Z2 = W2.dot(A1) + b2
    A2 = softmax(Z2)
    return Z1, A1, Z2, A2
```
### 3. Backward propagation:
```python
def backward_prop(Z1, A1, Z2, A2, W1, W2, X, Y): #backward propagation function
    one_hot_Y = one_hot(Y)
    dZ2 = A2 - one_hot_Y
    dW2 = 1 / m * dZ2.dot(A1.T)
    db2 = 1 / m * np.sum(dZ2)
    dZ1 = W2.T.dot(dZ2) * ReLU_deriv(Z1)
    dW1 = 1 / m * dZ1.dot(X.T)
    db1 = 1 / m * np.sum(dZ1)
    return dW1, db1, dW2, db2
```
## Materials used :
* https://www.youtube.com/watch?v=aircAruvnKk , for understanding an outline of neural networks
* https://www.youtube.com/watch?v=hfMk-kjRv4c , example project on neural networks
* https://www.youtube.com/watch?v=w8yWXqWQYmU , followed this guide closley to implement the neural network
* https://www.kaggle.com/datasets/oddrationale/mnist-in-csv/data , MNIST database
