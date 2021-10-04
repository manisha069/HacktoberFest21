import React, { PureComponent } from 'react';
import Header from './header';
import Card from './card';
import GameOver from './gameover';

class Memory extends PureComponent {

  state = {
    isFlipped: Array(16).fill(false),
    shuffledCard: MemoryGamePage.duplicateCard().sort(() => Math.random() - 0.5),
    clickCount: 1,
    prevSelectedCard: -1,
    prevCardId: -1
  };

  static duplicateCard = () => {
    return ["Galaga", "Pacman", "Dig Dug", "Frogger", "Donkey Kong", "Super Mario", "Tetris", "Mortal Combat"].reduce((preValue, current, index, array) => {
      return preValue.concat([current, current])
    }, []);
  };

  handleClick = event => {
    event.preventDefault();
    const cardId = event.target.id;
    const newFlipps = this.state.isFlipped.slice();
    this.setState({
      prevSelectedCard: this.state.shuffledCard[cardId],
      prevCardId: cardId
    });

    if (newFlipps[cardId] === false) {
      newFlipps[cardId] = !newFlipps[cardId];
      this.setState(prevState => ({
        isFlipped: newFlipps,
        clickCount: this.state.clickCount + 1
      }));

      if (this.state.clickCount === 2) {
        this.setState({ clickCount: 1 });
        const prevCardId = this.state.prevCardId;
        const newCard = this.state.shuffledCard[cardId];
        const previousCard = this.state.prevSelectedCard;

        this.isCardMatch(previousCard, newCard, prevCardId, cardId);
      }
    }
  };

  isCardMatch = (card1, card2, card1Id, card2Id) => {
    if (card1 === card2) {
      const hideCard = this.state.shuffledCard.slice();
      hideCard[card1Id] = -1;
      hideCard[card2Id] = -1;
      setTimeout(() => {
        this.setState(prevState => ({
          shuffledCard: hideCard
        }))
      }, 1000);
    } else {
      const flipBack = this.state.isFlipped.slice();
      flipBack[card1Id] = false;
      flipBack[card2Id] = false;
      setTimeout(() => {
        this.setState(prevState => ({ isFlipped: flipBack }));
      }, 1000);
    }
  };

  restartGame = () => {
    this.setState({
      isFlipped: Array(16).fill(false),
      shuffledCard: MemoryGamePage.duplicateCard().sort(() => Math.random() - 0.5),
      clickCount: 1,
      prevSelectedCard: -1,
      prevCardId: -1
    });
  };

  isGameOver = () => {
    return this.state.isFlipped.every((element, index, array) => element !== false);
  };

  render() {
    return (
      <div>
        <Header restartGame={this.restartGame} />
        {this.isGameOver() ? <GameOver restartGame={this.restartGame} /> :
          <div className="grid-container">
            {
              this.state.shuffledCard.map((cardNumber, index) =>
                <Card
                  key={index}
                  id={index}
                  cardNumber={cardNumber}
                  isFlipped={this.state.isFlipped[index]}
                  handleClick={this.handleClick}
                />
              )
            }
          </div>
        }
      </div>
    );
  }
}

export default Memory;