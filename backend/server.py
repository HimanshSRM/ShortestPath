from flask import Flask, request, jsonify
from flask_cors import CORS
import subprocess
import os

app = Flask(__name__)
CORS(app)

@app.route('/api/shortestpath', methods=['POST'])
def shortest_path():
    try:
        data = request.get_json()
        input_text = data.get('input', '')

        # Get absolute path to the .exe file
        current_dir = os.path.dirname(os.path.abspath(__file__))
        exe_path = os.path.join(current_dir, "singleSourceShortestPath.exe")

        print("Looking for executable at:", exe_path)
        if not os.path.exists(exe_path):
            return jsonify({'error': f'Executable not found at: {exe_path}'}), 500

        # Call the executable
        process = subprocess.Popen(
            [exe_path],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )

        stdout, stderr = process.communicate(input=input_text)

        if process.returncode != 0:
            print("C++ error:", stderr)
            return jsonify({'error': stderr}), 500

        return jsonify({'result': stdout})

    except Exception as e:
        print("Server error:", e)
        return jsonify({'error': str(e)}), 500

if __name__ == '__main__':
    print("Flask server running...")
    app.run(host='127.0.0.1', port=5000)
