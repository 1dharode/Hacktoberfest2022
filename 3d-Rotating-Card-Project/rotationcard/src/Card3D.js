// Card3D.jsx
import React from 'react';
import './styles.css';

const Card3D = ({ frontContent, backContent }) => {
    return (
        <div className="card-container">
            <div className="card">
                <div className="card-face card-front">
                    {frontContent || (
                        <>
                            <h2>Front Side</h2>
                            <p>Hover to see more</p>
                        </>
                    )}
                </div>
                <div className="card-face card-back">
                    {backContent || (
                        <>
                            <h2>Back Side</h2>
                            <p>This card flips on hover with Glassmorphism!</p>
                        </>
                    )}
                </div>
            </div>
        </div>
    );
};

export default Card3D;
