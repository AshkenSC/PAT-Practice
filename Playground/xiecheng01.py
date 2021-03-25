# 假设输入若干行
# 第一行，输入矩阵行和列：3，4
# 后面，输入矩阵内容
# 3 4 2 6
# 5 6 7 2
# 9 8 5 2

size = input()
size = size.split()
size = [int(num) for num in size]
a, b = size[0], size[1]

data = []
for i in range(a):
    line = input()
    line = line.split()
    line = [int(num) for num in line]
    data.append(line)

print(data)


class Net(torch.nn.Module):
    def __init__(self, n_feature, n_hidden, n_output):
        super(Net, self).__init__()
        self.hidden = torch.nn.Linear(n_feature, n_hidden)
        self.predict = torch.nn.Linear(n_hidden, n_output)

    def forward(self, x_input):
        x_hidden = F.relu(self.hidden(x_input))
        x_predict = self.predict(x_hidden)
        return x_predict
    net = Net(2, 10, 2)
    # print(net)
    opt = torch.optim.SGD(net.parameters(), lr=0.01)
    loss_func = torch.nn.CrossEntropyLoss()
for step in range(100):
        out = net(x)
        loss = loss_func(out, y)
        opt.zero_grad()
        loss.backward()
        opt.step()


# 神经网络numpy
import numpy as np

# N is batch size; D_in is input dimension;
# H is hidden dimension; D_out is output dimension.
N, D_in, H, D_out = 64, 1000, 100, 10

# Create random input and output data
x = np.random.randn(N, D_in)
y = np.random.randn(N, D_out)

# Randomly initialize weights
w1 = np.random.randn(D_in, H)
w2 = np.random.randn(H, D_out)

learning_rate = 1e-6
for t in range(500):
    # Forward pass: compute predicted y
    h = x.dot(w1)
    h_relu = np.maximum(h, 0)
    y_pred = h_relu.dot(w2)

    # Compute and print loss
    loss = np.square(y_pred - y).sum()
    print(t, loss)

    # Backprop to compute gradients of w1 and w2 with respect to loss
    
    # loss = (y_pred - y) ** 2
    grad_y_pred = 2.0 * (y_pred - y)
    # 
    grad_w2 = h_relu.T.dot(grad_y_pred)
    grad_h_relu = grad_y_pred.dot(w2.T)
    grad_h = grad_h_relu.copy()
    grad_h[h < 0] = 0
    grad_w1 = x.T.dot(grad_h)

    # Update weights
    w1 -= learning_rate * grad_w1
    w2 -= learning_rate * grad_w2


