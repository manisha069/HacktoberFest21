import React from "react";

const style = {
    background: "#08F300",
    border: "2px solid rgb(13, 13, 233)",
    fontSize: "70px",
    fontWeight: "800",
    cursor: "pointer",
    outline: "none"
}

const Square = ({ value, onClick }) => (
    <button style={style} onClick={onClick}>
        {value}
    </button>
);

export default Square;