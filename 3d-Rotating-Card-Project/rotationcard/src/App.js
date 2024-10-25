
import React from 'react';
import Card3D from './Card3D';
import './styles.css';

function App() {
    return (
        <div className="app">
            <h1>3D Rotating Card with React</h1>
            <Card3D 
                frontContent={<div><h2>Frontend Dev</h2><p>Explore More</p></div>} 
                backContent={<div><h2>Projects</h2><p>Check out my work</p></div>} 
            />
        </div>
    );
}

export default App;
