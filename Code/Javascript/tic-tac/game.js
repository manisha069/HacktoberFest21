import React, { useState } from "react";
import Board from "./board"
import { calculateWinner } from "./winner";

const styles = {
    width: "200px",
    margin: "20px auto",
    color: "white",
    fontSize: "20px"
}

const Game = () => {
    const [board, setBoard] = useState(Array(9).fill(null));
    const [xIsNext, setXisNext] = useState(true);
    const winner = calculateWinner(board);

    const handleClick = i => {
        const boardCopy = [...board];
        // If user clicks an occupied square or if game is won, then return
        if (winner || boardCopy[i]) return;
        // Put and X or and O in the clicked square
        boardCopy[i] = xIsNext ? "X" : "O";
        setBoard(boardCopy);
        setXisNext(!xIsNext);

    }
    const jumpTo = () => {

    }

    const renderMoves = () => (
        <button onClick={() => setBoard(Array(9).fill(null))}>
            Restart

        </button>

    )

    return (
        <>
            <Board squares={board} onClick={handleClick} />
            <div style={styles}>
                <p>{winner ? "Winner: " + winner : "Next Player: " + (xIsNext ? "X" : "O")}</p>
                {renderMoves()}
            </div>
        </>
    )
}

export default Game;