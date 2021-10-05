import React from 'react';

const GameOver = ({ restartGame }) => (
  <div className="justify-center">
    <h1>Game Over!</h1>
    <h3>A little memory practice never hurt anybody...</h3>
    <button className="restart-button" onClick={restartGame}>Play Again!</button>
  </div>
);

export default GameOver;