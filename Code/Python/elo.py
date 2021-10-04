import matplotlib.pyplot as plt
import numpy as np

winner_rank = []
loser_rank = []


def calc_prob(t1: float, t2: float):
    return t1 / (t1 + t2)


def expected(rank1: float, rank2: float):
    transform1 = pow(10, rank1 / 400)
    transform2 = pow(10, rank2 / 400)

    return calc_prob(t1=transform1, t2=transform2)


def det_rat_w(pre_w: float, prob_w: float, k_factor: int):
    return pre_w + k_factor * (1 - prob_w)


def det_rat_l(pre_l: float, prob_l: float, k_factor: int):
    return pre_l + k_factor * (0 - prob_l)


def loop_through(rw, rl, k, count):
    print(f"Rank_Winner: {round(rw, 2)}")
    print(f"Rank_Loser: {round(rl, 2)}")

    pw = expected(rw, rl)
    pl = expected(rl, rw)

    print(f"P_Winner {round(pw, 2)}")
    print(f"P_Loser {round(pl, 2)}")

    winner_rank.append(rw)
    loser_rank.append(rl)

    if count < 1:
        return
    return loop_through(
        det_rat_w(rw, pw, k),
        det_rat_l(rl, pl, k),
        k, count - 1
    )


def plot_data(x, y):
    plt.plot(x, y)

    plt.xlabel('Elo - axis')
    plt.ylabel('Ranking - axis')

    plt.title('ELO vs Ranking')

    plt.show()


r1 = 1000
r2 = 1500
k = 120
c = 2

loop_through(rw=r1, rl=r2, k=k, count=c)

w = np.array(winner_rank)
l = np.array(loser_rank)

diff_rank = []

length = len(winner_rank)
i = 0
while i < length - 1:
    diff_rank.append(winner_rank[i] - winner_rank[i + 1])
    i += 1
diff_elo = w - l

print(diff_elo)
print(diff_rank)

plot_data(x=diff_elo[:length - 1], y=diff_rank)
