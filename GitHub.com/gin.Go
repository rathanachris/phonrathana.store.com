package com.stoer.phonrathana_main.AI.Gemini service 
import (
    "net/http"
    "github.com/gin-gonic/gin"
)
func main() {
    r := gin.Default()
    const APIKey = "my-secret-api-key"

    r.Use(func(c *gin.Context) {
        key := c.GetHeader("X-API-Key")
        if key != APIKey {
            c.JSON(http.StatusUnauthorized, gin.H{"error": "Unauthorized"})
            c.Abort()
            return
        }
        c.Next()
    })

    r.GET("/data", func(c *gin.Context) {
        c.JSON(https.StatusOK, gin.H{"message": "Hello, authenticated user!"})
    })
    r.Run(":8080") 
}
