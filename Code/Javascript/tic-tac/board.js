import React from "react";
import Square from "./square"

const style = {
    border: "4px solid rgb(13, 13, 233)",
    borderRadius: "5px",
    width: "500px",
    height: "500px",
    margin: "auto",
    marginTop: "40px",
    display: "grid",
    gridTemplate: "repeat(3, 1fr) / repeat(3, 1fr)"
}

const Board = ({ squares, onClick }) => (
    <div style={style}>
        {squares.map((square, i) => (
            <Square key={i} value={square} onClick={() => onClick(i)} />
        ))}
    </div>
)

export default Board;