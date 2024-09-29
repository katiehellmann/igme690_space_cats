using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Draggable : MonoBehaviour
{

    Vector3 mousePosOffset;
    [SerializeField] Camera cam;

    private Vector3 getMouseWorldPos()
    {
        return cam.ScreenToWorldPoint(Input.mousePosition);
    }

    private void OnMouseDown()
    {
        mousePosOffset = gameObject.transform.position - getMouseWorldPos();
    }
    private void OnMouseDrag()
    {
        transform.position = getMouseWorldPos() + mousePosOffset;
    }
}
